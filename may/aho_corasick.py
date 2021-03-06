FAIL = -1
mpq={}


def aho_corasick(string, keywords):
    
    transitions = {}
    outputs = {}
    fails = {}

    new_state = 0

    for keyword in keywords:
        state = 0

        for j, char in enumerate(keyword):
            res = transitions.get((state, char), FAIL)
            if res == FAIL:
                break
            state = res

        for char in keyword[j:]:
            new_state += 1
            transitions[(state, char)] = new_state
            state = new_state

        outputs[state] = [keyword]

    queue = []
    for (from_state, char), to_state in transitions.items():
        if from_state == 0 and to_state != 0:
            queue.append(to_state)
            fails[to_state] = 0

    while queue:
        r = queue.pop(0)
        for (from_state, char), to_state in transitions.items():
            if from_state == r:
                queue.append(to_state)
                state = fails[from_state]

                while True:
                    res = transitions.get((state, char), state and FAIL)
                    if res != FAIL:
                        break
                    state = fails[state]

                failure = transitions.get((state, char), state and FAIL)
                fails[to_state] = failure
                outputs.setdefault(to_state, []).extend(
                    outputs.get(failure, []))

    ans=0
    temp=0
    state = 0
    results = []
    res_dic={}
    for i in keywords:
        res_dic[i] = 0
    for i, char in enumerate(string):
        while True:
            res = transitions.get((state, char), state and FAIL)
            if res != FAIL:
                state = res
                break
            state = fails[state]

        for match in outputs.get(state, ()):
            pos = i - len(match) + 1
            res_dic[match]=res_dic[match]+1
            ans = ans + mpq[match]
            # results.append((match, pos))

    return ans

# print(aho_corasick("asdfasgergfergf", ["dfasger", "dfa", "gf"]))

for _ in range(int(input())):
    a=input()
    b=input()
    n=int(input())
    lst=[]
    for i in range(n):
        key,temp=input().split()
        val=int(temp)
        mpq[key]=val
        # lst.append(key)
    
    left,right="",""
    ans=-1
    for i in range(len(a)):
        left=left+a[i]
        for j in range(len(b)-1,-1,-1):
            right=b[j]+right
            ans=max(ans,aho_corasick(left+right,mpq))
        right=""
    mpq.clear()
    print(ans)