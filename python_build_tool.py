import json
import subprocess

all_success_flag = True
failed_packages = []

with open('requirements.json') as f:
    text = f.read();
    dependencies = json.loads(text)["Dependencies"]
    
for dependency in dependencies:
    try:
        subprocess.check_call(["pip", "install", dependency])
    except subprocess.CalledProcessError:
         all_success_flag = False
         failed_packages.append(dependency)

if all_success_flag:
    print("Success!")
else:
    print("Failed to install the following packages")
    print("\n".join(failed_packages))
