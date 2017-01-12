x = [2.9, 3.0, 3.1, 3.2]
y = [-4.827866, -4.240058, -3.496909, -2.596792]

def derivadalarg_1_e_2(x0, x1, y0, y1):
    if x1 > x0:
        return (y1 - y0)/(x1 - x0)
    elif x0 > x1:
        return (y0 - y1)/(x0 - x1)
    else:
        return

def derivadalarg_3_e_3n(x0, x1, x2, y0, y1, y2):
    if (x0 < x1) and (x0 < x2):
        p1 = -3 * (y0)
        p2 = 4 * y1
        p3 = - y2
        h = x2 - x0
        return (p1 + p2 + p3) / h
    elif (x0 > x1) and (x0 > x2):
        p1 = -3 * (y2)
        p2 = 4 * y1
        p3 = - y0
        h = x0 - x2
        return (p1 + p2 + p3) / h
    else:
        return

def derivadalarg_4(x0, x1, x2, y0, y1, y2):
    p1 = y2 + y1
    h = x2 - x1
    return p1/h



d1 = derivadalarg_1_e_2(x[0], x[1], y[0], y[1])
d2 = derivadalarg_1_e_2(x[1], x[0], y[1], y[0])
d3 = derivadalarg_3_e_3n(x[0], x[1], x[2], y[0], y[1], y[2])
d4 = derivadalarg_4(x[1], x[0], x[2], y[1], y[0], y[2])

print(d2)
