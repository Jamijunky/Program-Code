import itertools

def shell_mistakes(arr):
    n = len(arr)
    # Shell can declare [L, R] to be fake (1-based index).
    # Mistakes = (T inside [L, R]) + (F outside [L, R])
    # T inside [L, R] = count of 1s in arr[L-1:R]
    # F outside [L, R] = (Total F) - (F inside [L, R])
    
    total_f = arr.count(-1)
    
    # Case 1: Shell declares all Real (no fake segment)
    min_errors = total_f
    
    # Case 2: Shell declares [i, j] to be fake
    for i in range(n):
        for j in range(i, n):
            segment = arr[i:j+1]
            t_in = segment.count(1)
            f_in = segment.count(-1)
            f_out = total_f - f_in
            min_errors = min(min_errors, t_in + f_out)
    return min_errors

def solve_brute(s):
    # Generate all ways to fill 'N'
    n = len(s)
    possibilities = []
    
    def fill(idx, current):
        if idx == n:
            possibilities.append(list(current))
            return
        if s[idx] == 'N':
            fill(idx + 1, current + [1])
            fill(idx + 1, current + [-1])
        else:
            val = 1 if s[idx] == 'T' else -1
            fill(idx + 1, current + [val])
            
    fill(0, [])
    
    # GLaDOS wants to maximize Shell's mistakes
    max_mistakes = 0
    for arrangement in possibilities:
        max_mistakes = max(max_mistakes, shell_mistakes(arrangement))
    return max_mistakes

# --- DP Solver (same logic as before) ---
def solve_dp(s):
    n = len(s)
    # dp[f][suf] = max_global_min
    dp = {} # Map (f, suf) -> max_global_min
    dp[(0, 0)] = 0
    
    for char in s:
        new_dp = {}
        for (f, suf), cur_g in dp.items():
            # Try T (+1)
            if char in ['T', 'N']:
                nsuf = min(1, suf + 1)
                nglob = min(cur_g, nsuf)
                if (f, nsuf) not in new_dp or new_dp[(f, nsuf)] < nglob:
                    new_dp[(f, nsuf)] = nglob
            # Try F (-1)
            if char in ['F', 'N']:
                nsuf = min(-1, suf - 1)
                nglob = min(cur_g, nsuf)
                if (f + 1, nsuf) not in new_dp or new_dp[(f + 1, nsuf)] < nglob:
                    new_dp[(f + 1, nsuf)] = nglob
        dp = new_dp
    
    ans = 0
    for (f, suf), global_min in dp.items():
        ans = max(ans, f + min(0, global_min))
    return ans

# --- Exhaustive Test ---
for n in range(1, 8):
    for p in itertools.product(['T', 'F', 'N'], repeat=n):
        s = "".join(p)
        brute = solve_brute(s)
        dp_res = solve_dp(s)
        if brute != dp_res:
            print(f"FAILED for {s}: Brute={brute}, DP={dp_res}")
            exit()
print("All cases passed for N <= 7.")