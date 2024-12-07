# 🌐 Web Crawler with Trie Structure

## 📖 Overview
This project is a **web crawler** developed for **CS232** at Purdue University Fort Wayne (PFW). The crawler traverses websites and stores the collected data in a **Trie structure** for quick, efficient information retrieval! 🚀

## ✨ Features
- 🌍 **Crawls websites** to gather data.
- 🧩 **Trie-based storage** for fast lookups.
- 🛠️ **Efficient text extraction** with the `getText.py` script.
- ⚙️ **Core web crawling** logic implemented in `indexPage.c`.
- 📋 Includes a **test script** to run test cases and verify functionality.

## 🔍 Why Trie?
The Trie data structure was chosen to efficiently store and retrieve information about crawled URLs. With its prefix-based organization, it enables:
- Quick lookups for partially matched strings.
- Memory-efficient storage of large sets of URLs.

## 📂 Project Structure
- **`indexPage.c`**: Main C file for the web crawler implementation.
- **`getText.py`**: Python script for text extraction from crawled data (runs automatically).
- **`runTestCases.sh`**: Shell script to execute test cases for the crawler.

## 🔧 Prerequisites
- **C Compiler**: Ensure you have `gcc` installed.
- **Python**: Required for running `getText.py` for text extraction.
- **Internet Access**: The crawler requires access to the web to gather data.

## 🚀 How to Run
1. **Compile the C Program**: 
   ```bash
   gcc -o indexPage indexPage.c
   pip intall beautifulsoup4

## 📝 Usage Examples
- **Basic Crawl**:
   ```bash
   ./indexPage https://example.com 2
   ```
  This command crawls the specified website up to a depth of 2.

