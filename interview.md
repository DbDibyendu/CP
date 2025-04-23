1. **Introduction**

Hi, I’m Dibyendu Biswas, a full stack engineer at JioStar for about 2 yrs now. I am in Payments and
Subscriptions team and my work invloves smooth functioning of Payment and paywall page and ensuring we
are getting those subscribers !! My daily work involves delivering features on the web, webLR and Mweb
client, while also contributing to badckend-for-frontend (BFF) development using Go. I graduated from
IIT Kharagpur in 2023, and beyond coding, I enjoy staying playings sports, hitting gym and making bike
trips.

2. **Discussion about your career aspirations and how they align with the company's roadmap? Why you're
   interested in this role and how you can contribute to the team?**

Ans:

I'm looking to make a switch because I’m at a point in my career where I want to take on broader
technical ownership and solve more meaningful, end-to-end problems. While I’ve gained strong experience
in performance tuning, payment flows, and handling large-scale feature rollouts, my current work in the
Payments and Subscriptions domain tends to impact the user experience in more indirect ways. What
excites me about the opportunity at GetSetYo is the chance to build user-facing features that directly
impact People: how people plan, book, and experience travel.

3. **What are ur strengths?**

I break down problems into sub problems, and try to solve each part as optimally. I incooprorate
feedback very well and try to work on them and improve. These are some things that my manager informed
works well for me.

4. **Weaknesses**

I at times focus too much on perfection, that sometimes leads to delay in feature delivery. It ensures
quality delivery but at times compromise the timelines.

This format is inspired by the book “Cracking the Coding Interview” by Gayle Laakmann McDowell

Recall stories from your past work experience and write down your answers:

**Story 1**

Situation:
I led the migration popup implementation across Android, iOS, and Web, ensuring seamless coordination
with the product team under strict deadlines.

Task:
The goal was to ensure a smooth user migration from the JC app to the JioHotstar app while handling
frequent requirement changes. Leading this project across teams (Android, iOS, QA, design).

Action:

1. Prioritized P0 items to meet tight deadlines
2. Managed evolving requirements and coordinated with Android and iOS teams for alignment
3. Guided the QA team for end-to-end testing
4. Worked extended hours, including weekends, to meet deadlines
5. Implemented a CDN-level panic setup to handle excessive backend load by serving 5xx responses to
   subsequent retry requests, preventing server failures

Result:

1. Successfully displayed the migration popup to 100M+ users
2. Ensured a smooth migration with minimal client and backend failures

**Story 2: Webview Optimisation**

Situation:
Our team was working on optimizing the performance of the payments page webview on Android, which had
the highest traffic among all platforms.

Task:
The objective was to reduce page load times for users, aiming to bring it below 5 seconds from 11
secs.

Action:

1. Conducted a detailed performance analysis to identify bottlenecks affecting load times
2. Preloaded the HTML shell, JavaScript, and CSS for the payment flow on the native Android app’s
   paywall page
3. Preloaded the shell from NetStorage, worked closely with the Akamai CDN team to optimize delivery
4. Performed JavaScript minification, image optimization, and lazy loading of non-critical UI
   components
5. Introduced a dedicated payments entry point, reducing the initial JavaScript chunk size

Result:
These optimizations led to a 70% reduction in page load times, bringing it down from 11 seconds to 3-4
seconds. This significantly improved the user payments reach rate and positively impacted our Payment
Success Rate (PSR)

**Story 3 : Paywall on LR Devices**

**Situation:**  
We needed to implement a new paywall experience for LR (Living Room) devices like Tizen and WebOS. There was  
no prior implementation and I was responsible for taking it from scratch.

**Task:**  
I had to design and implement a fully responsive and performant paywall UI that adhered to the provided Figma  
designs, worked across different Chrome versions (including very old ones, down to version 64), and could be  
scaled to support high daily user traffic.

**Action:**

- Followed the Figma design and built the UI from scratch using the Atomic Design approach
- Created base components (Atoms, Molecules, Organisms) for better reusability and structure
- Paid special attention to compatibility with Chrome 64 and other legacy environments
- Worked with the QA team to test and fix device/browser-specific issues
- Coordinated closely with the design and product team to iterate and refine experience
- Ensured the paywall handled various edge cases gracefully and kept performance consistent

**Result:**

- Successfully launched the new paywall experience on all supported LR devices
- No major post-launch issues on legacy browsers
- The new paywall sees **~60k users daily**, indicating a major impact on business reach and user interaction

**Common Questions**

Project 1: Payment Webview Optimisation

- Challenges: Payment page load time below 5 secs
- Mistakes/Failures: Initially on SSR which introduced more server load. Should have shifted to CSR
  earlier
- Technical Decisions: Used Akamai NetStorage to preload assets, introduced dynamic imports and new
  entry point
- Enjoyed: Direct impact on load times and success rate
- Leadership: Coordinated with Android and Akamai teams, proposed scalable solutions
- Conflicts: [You can fill this if needed]
- Tech Used: Nextjs, Preloading, JS minification, Akamai CDN, image compression, Lazy loading
- What I'd do differently: Shift to CSR earlier and save on server load

Project 2: Migration Popup

- Challenges: Trade-off between unique fcap per user type, and lack of fixed PRD
- Mistakes/Failures: Some deeplink edge cases mishandled
- Technical Decisions: CDN-based retry prevention, config-driven customization
- Enjoyed: 100M+ user impact, successful migration
- Leadership: Led migration across platforms, coordinated with QA, design, product teams
- Conflicts: [You can fill this if needed]
- Tech Used: Next.js, Akamai CDN, config-based platform logic
- What I'd do differently: Plan fallback mechanisms early

Project 3: Paywall on Web LR

- Challenges: Smooth animations on Web LR (Tizen, WebOS), device-specific features
- Mistakes/Failures: Lag on WebOS, broken UI on older browsers
- Technical Decisions: Optimized animations, ensured compatibility with older Chrome versions
- Enjoyed: New paywall now sees 20k+ daily impressions
- Leadership: Worked closely with design, product, QA to improve experience
- Conflicts: [You can fill this if needed]
- Tech Used: Web Animations API, Browserify, Next.js
- What I'd do differently: Optimize animation earlier, test more broadly

**Current Tech Stack of my project:**

At Hotstar, we follow a BFF (Backend-for-Frontend) architecture to render the UI and widgets
efficiently. Our web client is built using React, Next.js, TypeScript, and CSS, while the BFF layer is
developed in Golang for data population and widget creation. On the core backend, we primarily use
Java and Golang for handling business logic and data processing. We use Akamai as our CDN, EC2 for
deployments and Harness for CI/CD pipelines. For storage, afaik we rely on S3 and Redis, Dynamo DB.
For system orchestration and scaling we use Kubernetes.

**Questions for Manager**

- How will the day to day responsibility look like for someone in this role?
- What is the current scale of our consumer base?
- What’s the project roadmaps you guys follow in the team, for any feature delivery?
- What’s the size of the team, and size of the organisation?
