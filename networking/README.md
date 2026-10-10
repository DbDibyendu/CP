# End-to-end networking in PlantUML

Original explanatory diagrams organized around Kurose and Ross's *Computer Networking: A Top-Down Approach*. The references are the authors' public teaching material and IETF specifications; these are an original synthesis, not reproduced textbook figures.

## Start here

1. Read **01-overview** for the complete request and response in eight stages.
2. Read **04a-layer-stack** to place HTTP, TLS, sockets, TCP, IP, link, and physical operations.
3. Follow **02** for setup and DNS, **03** for connections/security, and **04** for packet forwarding and the return path.
4. Use **05** to understand delays and failure, and **06** to compare modern alternatives.

The six planned views are complemented by one compact layer-stack diagram. Every individual source has its own `@startuml`/`@enduml` block and requires no shared includes.

| Source | What to look for |
|---|---|
| [01-overview.puml](sources/01-overview.puml) | The whole journey; eight numbered stages matched to detail views. |
| [02-network-setup-and-dns.puml](sources/02-network-setup-and-dns.puml) | Ethernet/Wi-Fi readiness, DHCP, DNS caches and hierarchy, A/AAAA, encrypted DNS. |
| [03-sockets-tcp-and-tls.puml](sources/03-sockets-tcp-and-tls.puml) | Listener vs accepted socket, connection ports, TCP and TLS handshakes, protected HTTP, reuse and closure. |
| [04-all-layers-and-network-hops.puml](sources/04-all-layers-and-network-hops.puml) | Actual addresses, ARP, NICs, frames, switches, routers, optional NAT, TTL, MTU, physical signals, return delivery. |
| [04a-layer-stack.puml](sources/04a-layer-stack.puml) | Client and server layer stacks, encapsulation, physical links, device responsibilities. |
| [05-reliability-delays-and-failures.puml](sources/05-reliability-delays-and-failures.puml) | Byte ranges, lost segments, ACKs, retransmission, buffers/windows, delays, failure cases. |
| [06-ipv6-quic-and-tls-termination.puml](sources/06-ipv6-quic-and-tls-termination.puml) | Three independent panels for IPv6, HTTP/3 over QUIC, and proxy/CDN TLS endpoints. |

[end-to-end-networking.puml](end-to-end-networking.puml) contains all seven named diagrams. Editors that show only the first block should use an individual source instead.

## Render and zoom

Use an individual `.puml` file in your PlantUML editor and select **SVG** output. SVG preserves text and lines when zoomed. The detailed hop diagram is deliberately wide; pan across hosts and network devices at a comfortable reading scale.

With a current PlantUML JAR and Java 11 or newer, run from this directory:

```sh
java -Djava.awt.headless=true -DPLANTUML_LIMIT_SIZE=16384 \
  -jar /path/to/plantuml.jar -tsvg -o rendered end-to-end-networking.puml
```

This renders all seven named diagrams under `rendered/`. The stack companion uses PlantUML's bundled Smetana layout engine, so it does not require a separate Graphviz installation. The size setting accommodates the large detailed diagram, especially if you also render PNG previews.

Syntax/rendering documentation: [PlantUML sequence diagrams](https://plantuml.com/sequence-diagram), [layout engines](https://plantuml.com/layout-engines), [command-line rendering](https://plantuml.com/command-line).

## Read the protocol boundaries correctly

- **The five Internet layers are application, transport, network, link, physical.** TLS is shown above TCP and below HTTP; the socket API is shown as a local interface. Neither is an extra layer in that five-layer model.
- **Every network exchange uses the lower layers.** DNS, TCP setup, and TLS setup generate traffic before the HTTP request, using the same sorts of IP/link/physical operations detailed in 04.
- **End-to-end destinations and next hops differ.** IP identifies the remote destination; an Ethernet destination MAC typically identifies the next local hop. A normal switch forwards local frames; a router extracts and forwards the IP packet in new link encapsulation.
- **HTTP, TLS, TCP, and link boundaries differ.** Messages can span records/segments/frames. Receiving some socket bytes does not mean a complete application message is available.
- **Acknowledgments have different meanings.** A Wi-Fi link ACK is local. A TCP ACK confirms transport receipt. An HTTP response conveys application-level status, with semantics defined by that application.
- **Signals are generated separately for each physical link.** Copper electrical signaling, fiber optical signaling, and radio modulation carry encoded bits; switches and routers receive and transmit on their own interfaces.
- **Security ends at the TLS peer.** In a direct connection the server is the peer. A terminating CDN/proxy becomes the client's peer and creates or reuses a separate origin connection.

## Example assumptions

The baseline is a new HTTP/1.1 connection over IPv4/TCP with a full TLS 1.3 handshake and ordinary server authentication. Network configuration, DNS cache misses, ARP, and NAT are conditional. Resumption, client certificates, and ECH are not part of the baseline.

Use these illustrative values consistently:

| Role | Example |
|---|---|
| Client | `192.168.1.10:51514`, subnet `192.168.1.0/24` |
| Default gateway on client LAN | `192.168.1.1` |
| NAT public client endpoint | `198.51.100.10:62000` |
| HTTPS server | `203.0.113.20:443` |
| IPv6 client / server | `2001:db8:1::10` / `2001:db8:2::20` |

These are educational addresses, not the real DNS results for `www.example.com`. The public IPv4 and IPv6 examples use documentation ranges. `MAC_C`, `MAC_G_LAN`, etc. are symbolic local addresses. The main response example includes NAT; a note explains its absence in a private routed network. Real routes, encapsulations, NIC offloads, and asynchronous APIs can vary.

The figures explain the packet journey rather than every detail of physical engineering or ISP infrastructure. Wireless modulation, media, forwarding, and protocol variations are represented at the level needed to follow that journey.

## Glossary

| Term | Meaning in these diagrams |
|---|---|
| DNS / TTL | Domain Name System / cache lifetime for DNS records; IP TTL separately limits packet lifetime in hops. |
| DHCP / SLAAC | Dynamic Host Configuration Protocol / stateless IPv6 address autoconfiguration. |
| Socket | Application interface to a transport endpoint; not a wire protocol. |
| TLS / SSL | Transport Layer Security / its historical predecessor; TLS is the illustrated protocol. |
| SNI / ALPN | Server Name Indication / Application-Layer Protocol Negotiation in TLS. |
| AEAD | Authenticated encryption with associated data. |
| TCP / UDP | Transmission Control Protocol byte stream / User Datagram Protocol datagrams. |
| QUIC | Secure transport carrying HTTP/3 streams over UDP. |
| MSS / MTU | Maximum TCP segment payload / maximum IP packet supported by a link. |
| IP / ICMP | Internet Protocol / Internet Control Message Protocol for control and error reporting. |
| ARP / ND | IPv4 Address Resolution Protocol / IPv6 Neighbor Discovery for local neighbor information. |
| MAC / NIC / PHY | Media access control / network interface controller / physical-layer transceiver. |
| FCS / CRC | Frame check sequence / cyclic redundancy check for accidental frame corruption. |
| NAT | Network address translation; the example also translates a source port. |
| OSPF / BGP | Open Shortest Path First / Border Gateway Protocol for routing control. |
| AS / IGP | Autonomous system / interior gateway protocol. |
| RTT | Round-trip time. |
| rwnd / cwnd | Receiver-advertised window / sender congestion window. |
| CDN / AP | Content delivery network / wireless access point. |
| OFDM / CSMA/CA | Orthogonal frequency division multiplexing / carrier sense multiple access with collision avoidance. |

## References by topic

### Kurose and Ross: public teaching material

- [Chapter 1: Internet, physical media, delays, layering](https://gaia.cs.umass.edu/kurose_ross/videos/1/).
- [Chapter 2: HTTP, DNS, sockets, CDN](https://gaia.cs.umass.edu/kurose_ross/videos/2/).
- [Chapter 3: transport, TCP, reliability, congestion](https://gaia.cs.umass.edu/kurose_ross/videos/3/).
- [Chapter 4: router internals, IP, NAT, forwarding](https://gaia.cs.umass.edu/kurose_ross/videos/4/).
- [Chapter 5: routing control, OSPF, BGP, ICMP](https://gaia.cs.umass.edu/kurose_ross/videos/5/).
- [Chapter 6: link layer, Ethernet, ARP, switching; section 6.7, A Day in the Life of a Web Page Request](https://gaia.cs.umass.edu/kurose_ross/videos/6/).

### IETF specifications

| Topic | Primary references |
|---|---|
| DHCP | [RFC 2131](https://www.rfc-editor.org/rfc/rfc2131), [options: RFC 2132](https://www.rfc-editor.org/rfc/rfc2132) |
| DNS | [RFC 1034](https://www.rfc-editor.org/rfc/rfc1034), [RFC 1035](https://www.rfc-editor.org/rfc/rfc1035), [negative caching: RFC 2308](https://www.rfc-editor.org/rfc/rfc2308) |
| DNS security / encryption | [DNSSEC: RFC 4033](https://datatracker.ietf.org/doc/html/rfc4033), [DoT: RFC 7858](https://www.rfc-editor.org/rfc/rfc7858), [DoH: RFC 8484](https://www.rfc-editor.org/rfc/rfc8484) |
| TCP and congestion | [RFC 9293](https://www.rfc-editor.org/rfc/rfc9293), [RFC 5681](https://www.rfc-editor.org/rfc/rfc5681) |
| TLS and service identity | [TLS 1.3: RFC 8446](https://www.rfc-editor.org/rfc/rfc8446), [identity verification: RFC 9525](https://datatracker.ietf.org/doc/html/rfc9525) |
| HTTP | [semantics: RFC 9110](https://datatracker.ietf.org/doc/html/rfc9110), [HTTP/1.1: RFC 9112](https://datatracker.ietf.org/doc/html/rfc9112), [HTTP/2: RFC 9113](https://datatracker.ietf.org/doc/html/rfc9113) |
| IPv4, ARP, NAT | [RFC 791](https://www.rfc-editor.org/rfc/rfc791), [RFC 826](https://www.rfc-editor.org/rfc/rfc826), [RFC 3022](https://www.rfc-editor.org/rfc/rfc3022) |
| Path MTU | [IPv4: RFC 1191](https://www.rfc-editor.org/rfc/rfc1191), [IPv6: RFC 8201](https://datatracker.ietf.org/doc/html/rfc8201), [datagram probe-based discovery: RFC 8899](https://datatracker.ietf.org/doc/html/rfc8899) |
| IPv6 | [RFC 8200](https://www.rfc-editor.org/rfc/rfc8200), [ND: RFC 4861](https://www.rfc-editor.org/rfc/rfc4861), [SLAAC: RFC 4862](https://datatracker.ietf.org/doc/html/rfc4862), [Happy Eyeballs: RFC 8305](https://datatracker.ietf.org/doc/html/rfc8305) |
| HTTP/3 and QUIC | [QUIC: RFC 9000](https://www.rfc-editor.org/rfc/rfc9000), [TLS integration: RFC 9001](https://www.rfc-editor.org/rfc/rfc9001), [HTTP/3: RFC 9114](https://www.rfc-editor.org/rfc/rfc9114) |

## Validation

All seven standalone sources and the combined source were rendered locally to SVG using PlantUML 1.2026.8 and OpenJDK 21.0.9. SVG text was checked against image bounds. PNG previews were generated for visual review of the overview, layer-stack companion, all-diagram contact sheet, and a detailed hop crop. The source-only archive contains the sources and this guide; renderer binaries and validation previews are kept separately.
