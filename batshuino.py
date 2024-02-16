import os
import argparse
from embedder import BatuinoEmbedder

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Embed a Batsh script with Batuino")
    parser.add_argument("-i", "--input", help="Input Batsh script file", required=True)
    parser.add_argument("-o", "--output", help="Output file for compiled Batsh script (.ino)", required=True)
    args = parser.parse_args()

    embedder = BatuinoEmbedder()
    embedder.embed_batsh_with_batuino(args.input, args.output)