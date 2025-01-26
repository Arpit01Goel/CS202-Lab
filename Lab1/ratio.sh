# #!/bin/bash

# g++ main.cpp
# output_cpp=$(./a.out)

# output_python=$(python3 main.py)

# answer=$(echo "scale=2; $output_python / $output_cpp" |bc)
# echo "ratio: $answer"

#!/bin/bash

# Function to calculate the nth Fibonacci number in C++
run_cpp() {
    g++ main.cpp -o main_cpp
    ./main_cpp
}

# Function to calculate the nth Fibonacci number in Python
run_python() {
    python3 main.py
}

# Function to calculate the nth Fibonacci number in Java
run_java() {
    javac Main.java
    java Main
}

# Function to calculate the nth Fibonacci number in JavaScript
run_js() {
    node main.js
}

# Function to calculate the nth Fibonacci number in Bash
run_bash() {
    ./main.sh
}

# Run all the functions and store the results
output_cpp=$(run_cpp)
output_python=$(run_python)
output_java=$(run_java)
output_js=$(run_js)
output_bash=$(run_bash)

# Calculate the ratios
ratio_python=$(echo "scale=2; $output_python / $output_cpp" | bc)
ratio_java=$(echo "scale=2; $output_java / $output_cpp" | bc)
ratio_js=$(echo "scale=2; $output_js / $output_cpp" | bc)
ratio_bash=$(echo "scale=2; $output_bash / $output_cpp" | bc)

# Print the results
echo "C++: $output_cpp (baseline)"
echo "Python: $output_python (ratio: $ratio_python)"
echo "Java: $output_java (ratio: $ratio_java)"
echo "JavaScript: $output_js (ratio: $ratio_js)"
echo "Bash: $output_bash (ratio: $ratio_bash)"
