import os
import pathlib

DIRS = ["src", "tests"]
CLANG_COMMAND = "clang-format -i {file}"
EXTENSIONS = [".cpp", ".hpp", ".c", ".h"]

for dir in DIRS:
    for file in pathlib.Path(dir).rglob("*"):
        if file.suffix in EXTENSIONS:
            command = CLANG_COMMAND.format(file=file)
            print(command)
            os.system(command)
            
print("Formatting main.c")
os.system("clang-format -i main.c")
