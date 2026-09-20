

def split_and_join(line):
    # split the string by space
    line = line.split(" ")
    
    # join the string using hyphen
    return "-".join(line)

if __name__ == '__main__':
    line = input()
    result = split_and_join(line)
    print(result)