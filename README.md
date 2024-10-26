# Web Crawler with Trie Structure

## Overview
This project is a web crawler developed for **CS232** at Purdue University Fort Wayne (PFW). The web crawler traverses a website and stores the collected data in a **Trie structure**, allowing efficient retrieval and storage of information.

## Features
- Crawls a given website and collects data.
- Stores the crawled data in a Trie data structure for fast lookups.
- Efficient text extraction using the `getText.py` script.
- Provides basic C-based web crawling functionality in `indexPage.c`.
- Includes a script to run test cases for the project.

## Project Structure
- `indexPage.c`: The main C file containing the web crawler implementation.
- `getText.py`: A Python script to extract text from crawled data. The program automatically uses this.
- `runTestCases.sh`: Shell script to run various test cases on the crawler.

## How to Run
1. **Compile the C Program**: 
   ```bash
   gcc -o indexPage indexPage.c
