#!/bin/bash

cd "$(dirname "$0")"

for file in *; do
    if [[ "$file" == *"-"* ]]; then
        new_file=$(echo "$file" | tr '-' '_')
        mv "$file" "$new_file"
    fi
done