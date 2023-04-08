from pathlib import Path
import subprocess
 
directory = 'benchmark_set'
files = Path(directory).glob('*.hgr')

def run_flag():
    for file in files:
        process_one = subprocess.run(['build/Debug/fm.exe', '-m', file])

def run():
    for file in files:
        process_one = subprocess.run(['build/Debug/fm.exe', file])

run()
run_flag()