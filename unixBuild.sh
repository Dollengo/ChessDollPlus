#!/bin/bash

# Define the source file and the output executable
SOURCE_FILE="main.cpp"
OUTPUT_FILE="chessdollplus"

# Check if the source file exists
if [ ! -f "$SOURCE_FILE" ]; then
  echo "Source file $SOURCE_FILE not found!"
  exit 1
fi

# Compile the source file
g++ -o "$OUTPUT_FILE" "$SOURCE_FILE"

# Check if the compilation was successful
if [ $? -eq 0 ]; then
  echo "Compilation successful. You can run the game with ./$OUTPUT_FILE"
else
  echo "Compilation failed!"
  exit 1
fi
