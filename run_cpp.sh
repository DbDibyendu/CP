#!/usr/bin/env bash

# Set file names
CPP_FILE=$1
INPUT_FILE=${2:-testcases/input.txt}
OUTPUT_FILE=${3:-testcases/output.txt}
RESULT_FILE=${4:-testcases/result.txt}

# Check if g++ is installed
if ! command -v g++ &> /dev/null; then
    echo "g++ not found. Please install GCC using 'brew install gcc'."
    exit 1
fi

# Use GCC to compile the C++ file
g++ -std=c++17 -o program "$CPP_FILE"
if [ $? -ne 0 ]; then
    echo "Compilation failed!"
    exit 1
fi

# Run the compiled program
./program < "$INPUT_FILE" > "$RESULT_FILE"

# Show the program's output
echo "Program Output:"
cat "$RESULT_FILE"

# Optional: Compare with expected output
if [ -f "$OUTPUT_FILE" ]; then
    echo "Comparing with expected output..."
    diff -u "$OUTPUT_FILE" "$RESULT_FILE" && echo "Output matches expected!" || echo "Output differs!"
fi
