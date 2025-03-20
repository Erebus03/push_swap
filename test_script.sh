#!/bin/bash

# Number of test runs
num_tests=1000

# Counter for successful runs
successful=0

# Variable to track the maximum number of operations
max_ops=0

echo "Running push_swap test $num_tests times with 500 numbers each..."

for ((i=1; i<=num_tests; i++)); do
    # Generate 500 unique random arguments between -10000 and 10000
    args=$(seq -10000 10000 | shuf -n 100 | tr '\n' ' ')
    
    # Run the program with the random arguments and capture operations
    output=$(./pushswap $args 2>/dev/null)
    exit_code=$?
    
    # Count operations (number of lines in output)
    ops_count=$(echo "$output" | wc -l)
    
    # Check if the command was successful
    if [ $exit_code -eq 0 ]; then
        successful=$((successful+1))
        echo "Test $i: Operations: $ops_count"
        
        # Update max_ops if the current ops_count is higher than max_ops
        if [ $ops_count -gt $max_ops ]; then
            max_ops=$ops_count
        fi
    else
        echo "Segfault detected on test $i with args: $args"
    fi
    
    # Print progress every 10 tests
    if [ $((i % 10)) -eq 0 ]; then
        echo "Completed $i/$num_tests tests..."
    fi
done

echo "Tests completed. $successful/$num_tests tests passed successfully."
echo "Maximum operations in a single test: $max_ops"




# #!/bin/bash

# # Number of test runs
# num_tests=1000

# # Counter for successful runs
# successful=0

# echo "Running push_swap test $num_tests times with 500 numbers each..."

# for ((i=1; i<=num_tests; i++)); do
#     # Generate 500 unique random arguments between -10000 and 10000
#     args=$(seq -10000 10000 | shuf -n 100 | tr '\n' ' ')
    
#     # Run the program with the random arguments and capture operations
#     output=$(./pushswap $args 2>/dev/null)
#     exit_code=$?
    
#     # Count operations (number of lines in output)
#     ops_count=$(echo "$output" | wc -l)
    
#     # Check if the command was successful
#     if [ $exit_code -eq 0 ]; then
#         successful=$((successful+1))
#         echo "Test $i: Operations: $ops_count"
#     else
#         echo "Segfault detected on test $i with args: $args"
#     fi
    
#     # Print progress every 10 tests
#     if [ $((i % 10)) -eq 0 ]; then
#         echo "Completed $i/$num_tests tests..."
#     fi
# done

# echo "Tests completed. $successful/$num_tests tests passed successfully."
