#!/bin/bash

num_tests=20
total_time=0
log_file="out.log"

echo "Running $num_tests tests..."
echo "Results will be logged to: $log_file"

# Create or truncate the log file
echo "TEST FILE" > "$log_file"

for ((i=1; i<=$num_tests; i++)); do
    start_time=$(date +%s%N)
    python3 solver.py >> "$log_file"
    end_time=$(date +%s%N)
    elapsed_time=$((($end_time - $start_time)/1000000000))
    total_time=$((total_time + $elapsed_time))
    progress=$((i * 100 / num_tests))
    printf "Progress: [%-50s] %d%%\r" $(printf "#%.0s" $(seq 1 $((progress / 2)))) "$progress"
done

average_time=$((total_time / num_tests))
echo -e "\n\nAverage solving time: $average_time seconds"
echo "Results are logged in: $log_file"
