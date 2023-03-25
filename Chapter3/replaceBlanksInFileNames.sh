#!/bin/bash

# Navigate to the current folder
cd "$(dirname "$0")"

# Loop through all files in the current directory
for file in *; do
    # Check if the file name contains blank spaces
    # * here used as wildcard to match anything
    # [[ ]] is a conditional expression
    # == is a comparison operator that checks if the value of the 
    # variable file matches a pattern specified on the right side 
    # of the operator.
    if [[ "$file" == *" "* ]]; then
        # Replace all the blank spaces with underscores
        # tr is a command to translate/replace ' ' to '_'
        new_file=$(echo "$file" | tr ' ' '_')
        # Rename the file
        mv "$file" "$new_file"
    fi
done