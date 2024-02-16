import subprocess
import sys
import os

class BatuinoEmbedder:
    def __init__(self):
        self.batsh_path = "batsh/batsh.py"  # Update the path to batsh.py accordingly
        self.batuino_path = "batuino/batuino.py"  # Update the path to batuino.py accordingly

    def compile_batsh_to_batch(self, batsh_file, output_file):
        # Compile Batsh script to Batch script
        try:
            batsh_cmd = f"python {self.batsh_path} --winbat -i {batsh_file} -o {output_file}"
            subprocess.run(batsh_cmd, shell=True, check=True)
            print("Batsh script compiled to Batch script successfully.")
        except subprocess.CalledProcessError as e:
            print(f"Error: Failed to compile Batsh script to Batch script: {e}")

    def embed_batch_with_batuino(self, batch_script, arduino_file):
        # Embed Batch script with Batuino
        try:
            batuino_cmd = f"python {self.batuino_path} -i {batch_script} -o {arduino_file}"
            subprocess.run(batuino_cmd, shell=True, check=True)
            print("Batch script embedded with Batuino successfully.")
        except subprocess.CalledProcessError as e:
            print(f"Error: Failed to embed Batch script with Batuino: {e}")

    def embed_batsh_with_batuino(self, batsh_file, output_file):
        batch_script = f'{batsh_file.split('.')[0]}.bat'
        # Compile Batsh script to Batch script
        self.compile_batsh_to_batch(batsh_file, batch_script)

        # Embed Batch script with Batuino
        self.embed_batch_with_batuino(batch_script, output_file)