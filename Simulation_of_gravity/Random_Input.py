import random

def Random_points(n):

    random.seed()
    points = []

    for i in range(n):
        mass = str(random.uniform(0., 1000.))
        x = str(int(random.uniform(0.0, 200.0)))
        y = str(int(random.uniform(0.0, 200.0)))
        points.append([mass, x, y])

    return points