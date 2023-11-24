import re

def generate_tac(c_code):
    lines = c_code.split("\n")
    tac = []
    temp_counter = 0

    def new_temp():
        nonlocal temp_counter
        temp_counter += 1
        return f"t{temp_counter}"

    inside_loop = False

    for line in lines:
        line = line.strip()

        # Variable initialization (int a = 1;)
        match = re.match(r"int (\w+) *= *(\d+);", line)
        if match:
            var, value = match.groups()
            tac.append(f"{var} = {value}")
            continue

        # For loop start (for (int i = 1; i <= 10; i++))
        match = re.match(r"for \(int (\w+) *= *(\d+); *\w+ (<=|<|>|>=) *\d+; *\w+\+\+\)", line)
        if match:
            var, init_value = match.groups()[:2]
            tac.append(f"{var} = {init_value}")
            tac.append("L1:")
            inside_loop = True
            continue

        # Inside for loop
        if inside_loop:
            # Condition check (i <= 10)
            match = re.search(r"(\w+) (<=|<|>|>=) (\d+)", line)
            if match:
                var, op, value = match.groups()
                tac.append(f"if not ({var} {op} {value}) goto L2")
                continue

            # Increment (i++)
            if re.search(r"\w+\+\+", line):
                var = re.search(r"(\w+)\+\+", line).group(1)
                tac.append(f"{var} = {var} + 1")
                tac.append("goto L1")
                inside_loop = False
                continue

            # Inside loop assignments (a = a + 1)
            match = re.match(r"(\w+) *= *(\w+) *\+ *(\d+);", line)
            if match:
                var, expr_var, value = match.groups()
                temp = new_temp()
                tac.append(f"{temp} = {expr_var} + {value}")
                tac.append(f"{var} = {temp}")
                continue

    tac.append("L2:")
    return "\n".join(tac)

c_code = """
#include <stdio.h>

int main() {
int a=1;
    for (int i = 1; i <= 10; i++) {
       a=a+1;
    }
}
"""

print(generate_tac(c_code))
