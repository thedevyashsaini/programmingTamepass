try:
    m1, n1 = list(map(int, input().split()))
    mat1 = []
    mat2 = []
    for _ in range(m1):
        mat1.append(list(map(int, input().split())))

    m2, n2 = list(map(int, input().split()))
    for _ in range(m2):
        mat2.append(list(map(int, input().split())))

    if n1 != m2:
        print("ERR multiplication not possible")
        exit()

    mat3 = [[0 for _ in range(n2)] for _ in range(m1)]

    for i in range(m1):
        for j in range(n2):
            for k in range(n1):
                mat3[i][j] += mat1[i][k] * mat2[k][j]

            print(mat3[i][j], end=" ")
        print()
except Exception as e:
    print(f"You Messed up: {e}")