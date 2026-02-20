import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')

with open('cube.dat', 'r') as f:
    lines = f.readlines()

blocks = []
current_block = []
for line in lines:
    stripped = line.strip()
    if stripped == '':
        if current_block:
            blocks.append(current_block)
            current_block = []
    else:
        # Convert line to list of floats
        points = list(map(float, stripped.split()))
        current_block.append(points)

if current_block:
    blocks.append(current_block)

for block in blocks:
    if len(block) == 2:
        # Draw a single segment
        x = [block[0][0], block[1][0]]
        y = [block[0][1], block[1][1]]
        z = [block[0][2], block[1][2]]
        ax.plot(x, y, z, 'b-')
    else:
        # Draw a polyline
        for i in range(len(block)-1):
            x = [block[i][0], block[i+1][0]]
            y = [block[i][1], block[i+1][1]]
            z = [block[i][2], block[i+1][2]]
            ax.plot(x, y, z, 'b-')

plt.show()
