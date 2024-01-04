import sys
import re
import json

REGDICT = {}
INSTRUCTION_DICT = {}
OUTPUT_FILE = open("../Instructions.coe", "w")


def two_comp(num, nbits):
    '''
    gives nbit long two complement representation of number
    '''
    if num >= 0:
        return f"{num:0{nbits}b}"
    else:
        return f"{((1<<nbits)+num):0{nbits}b}"


def spit_line(line):
    try:
        # print(line)
        opcode = INSTRUCTION_DICT[line[0]][0]
        opc = int(opcode, 2)
        # print(opc)
        if opc == 1 or opc == 0:  # R type
            if len(line) != 3:
                print(f"error in line {line}")
                return
            else:
                rt = f"{REGDICT[line[1]]:05b}"
                rs = f"{REGDICT[line[2]]:05b}"
                shamt = f"{0:05b}"
                funct = f"{INSTRUCTION_DICT[line[0]][-1]}"
                dc = f"{0:05b}"
                print(f"{opcode}{rs}{rt}{shamt}{funct}{dc},", file=OUTPUT_FILE)
        elif opc == 2:
            if len(line) != 3:
                print(f"error in line {line}")
                return
            else:
                rs = f"{REGDICT[line[1]]:05b}"
                funct = f"{INSTRUCTION_DICT[line[0]][-1]}"
                shamt = f"{0:010b}"
                dc = f"{0:05b}"
                if line[2] in REGDICT:
                    rt = f"{REGDICT[line[2]]:05b}"
                else:
                    shamt = f"{int(line[2]):05b}"
                print(f"{opcode}{rs}{rs}{shamt}{funct}{dc},", file=OUTPUT_FILE)
        elif opc == 16:  # addi
            if len(line) < 2:
                print(f"error in line {line}")
                return
            else:
                rt = f"{REGDICT[line[1]]:05b}"
                imm = two_comp(int(line[2]), 16)
                print(f"{opcode}{rt}{rt}{imm},", file=OUTPUT_FILE)
        elif opc == 17:  # compi
            if len(line) < 2:
                print(f"error in line {line}")
                return
            else:
                rt = f"{REGDICT[line[1]]:05b}"
                imm = two_comp(int(line[2]), 16)
                print(f"{opcode}{rt}{rt}{imm},", file=OUTPUT_FILE)
        elif opc == 33:  # br
            rs = f"{REGDICT[line[1]]:05b}"
            addr = f"{0:016b}"
            dc = f"{0:05b}"
            print(f"{opcode}{rs}{dc}{addr},", file=OUTPUT_FILE)
        elif opc == 32:  # b
            rs = f"{0:05b}"
            addr = f"{int(line[1]):016b}"
            dc = f"{0:05b}"
            print(f"{opcode}{rs}{dc}{addr},", file=OUTPUT_FILE)
        elif opc == 35:  # bz
            rs = f"{REGDICT[line[1]]:05b}"
            addr = f"{int(line[2]):016b}"
            dc = f"{0:05b}"
            print(f"{opcode}{rs}{dc}{addr},", file=OUTPUT_FILE)
        elif opc == 36:  # bnz
            rs = f"{REGDICT[line[1]]:05b}"
            addr = f"{int(line[2]):016b}"
            dc = f"{0:05b}"
            print(f"{opcode}{rs}{dc}{addr},", file=OUTPUT_FILE)
        elif opc == 34:  # bltz
            rs = f"{REGDICT[line[1]]:05b}"
            addr = f"{int(line[2]):016b}"
            dc = f"{0:05b}"
            print(f"{opcode}{rs}{dc}{addr},", file=OUTPUT_FILE)
        elif opc == 37:  # bl
            rs = f"{0:05b}"
            addr = f"{int(line[1]):016b}"
            dc = f"{0:05b}"
            print(f"{opcode}{rs}{dc}{addr},", file=OUTPUT_FILE)
        elif opc == 18:  # lw
            rt = f"{REGDICT[line[1]]:05b}"
            imm = two_comp(int(line[2]), 16)
            rs = f"{0:05b}"
            if (len(line) == 4):
                rs = f"{REGDICT[line[3]]:05b}"
            print(f"{opcode}{rs}{rt}{imm},", file=OUTPUT_FILE)
        elif opc == 19:  # sw
            rt = f"{REGDICT[line[1]]:05b}"  # to be written
            imm = two_comp(int(line[2]), 16)
            rs = f"{0:05b}"
            if (len(line) == 4):
                rs = f"{REGDICT[line[3]]:05b}"
            print(f"{opcode}{rs}{rt}{imm},", file=OUTPUT_FILE)
        elif opc == 5 or opc == 4:
            if len(line) != 2:
                print(f"error in line {line}")
                return
            else:
                funct = f"{INSTRUCTION_DICT[line[0]][-1]}"
                rs = f"{0:05b}"
                addr = f"{int(line[1]):016b}"
                print(f"{opcode}{rs}{addr}{funct},", file=OUTPUT_FILE)
        elif opc == 60 or opc == 61:
            if len(line) != 3:
                print(f"error in line {line}")
                return
            else:
                rs = f"{REGDICT[line[1]]:05b}"
                rt = f"{0:05b}"
                imm_dec = int(line[2])
                imm = two_comp(imm_dec, 16)
                print(f"{opcode}{rs}{rt}{imm},", file=OUTPUT_FILE)
        elif opc == 62 or opc == 63:
            if len(line) != 4:
                print(f"error in line {line}")
                return
            else:
                rt = f"{REGDICT[line[1]]:05b}"
                rs = f"{REGDICT[line[-1]]:05b}"
                imm_dec = int(line[2])
                imm = two_comp(imm_dec, 16)
                print(f"{opcode}{rs}{rt}{imm},", file=OUTPUT_FILE)
    except Exception as e:
        print(e)
        print(f"error in line {line}")


def bin_comm(string):
    string = re.sub(re.compile("/'''.*?\'''", re.DOTALL), "", string)
    string = re.sub(re.compile("#.*?\n"), "", string)
    return string


def process(filename):
    print("memory_initialization_radix=2;", file=OUTPUT_FILE)
    print("memory_initialization_vector=", file=OUTPUT_FILE)
    print(f"11111111111111111111111111111111,", file=OUTPUT_FILE)
    with open(filename, 'r') as f:
        lines = f.readlines()
        for line in lines:
            line.strip()
            line = bin_comm(line)
            # print(line)

            line = line.replace(',', ' ').replace(
                ')', ' ').replace('(', ' ').split()
            if len(line):
                spit_line(line)
    print(f"11111111111111111111111111111111;", file=OUTPUT_FILE)


if __name__ == '__main__':
    with open('instruction.json', 'r') as f:
        INSTRUCTION_DICT = json.load(f)
    with open('register.json', 'r') as f:
        REGDICT = json.load(f)
    process(sys.argv[1])
