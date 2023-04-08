from pathlib import Path
import os
import subprocess
import threading as th
 
directory = 'benchmark_set'
files = Path(directory).glob('ISPD*.hgr')
print(files)

def doProcessing(flag):
    for file in files:
        process_one = subprocess.run(['build/Debug/fm.exe', flag, file])

def doProcessing():
    for file in files:
        process_one = subprocess.run(['build/Debug/fm.exe', file])



doProcessing()
doProcessing('-m')