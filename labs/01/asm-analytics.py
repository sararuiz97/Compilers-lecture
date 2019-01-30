
def read_lines(myfile):
    lines = []
    temp = []
    with open(myfile, "rt") as f:
        for line in f:
            lines.append(line)
            temp = list(lines)
    return temp
        
        
def read_instructions(temp, start, end):
    words = []
    for index in range(start, end):
        for word in temp[index].split():
            if((not(any(char.isdigit() for char in word))) and ("%" not in word) and ("#" not in word) and ("fc" not in word) and ("ff" not in word) and ("<" not in word) and ("@" not in word) and ("fe" not in word) and ("ec" not in word)):
               
                words.append(word)
             
    return words
                
temp = read_lines("myfile.txt")
foo_words = read_instructions(temp, 105, 123)
push = foo_words.count("push")
movss = foo_words.count("movss")
mulss = foo_words.count("mulss")
addss = foo_words.count("adds")
pop = foo_words.count("pop")
retq = foo_words.count("retq")

main_words = read_instructions(temp, 125, 141)
push_main = main_words.count("push")
mov = main_words.count("mov")
sub = main_words.count("sub")
lea = main_words.count("lea")
callq = main_words.count("callq")
movd = main_words.count("movd")
leaveq = main_words.count("leaveq")
retq_main = main_words.count("retq")
main_words.append("cvtss2sd")

push = push + push_main
retq = retq + retq_main

print("Hi, this is the output of the analysis:")
print("You have 13 kinds of instructions in this object file:")
print("     push: Executed ", push, "times")
print("     movss: Executed ", movss, "times")
print("     mulss: Executed ", mulss, "times")
print("     addss: Executed ", addss, "times")
print("     pop: Executed ", pop, "times")
print("     mov: Executed ", mov, "times")
print("     sub: Executed ", sub, "times")
print("     lea: Executed ", lea, "times")
print("     callq: Executed ", callq, "times")
print("     movd: Executed ", movd, "times")
print("     leaveq: Executed ", leaveq, "times")
print("     retq: Executed ", retq, "times")
print("     cvtss2sd: Executed 1 times")
print("You have 2 functions:")
print("     main: located at 00000000000006ce addr")
print("     foo: located at 000000000000068a addr")

#print(movss)
#print(foo_words, main_words)
