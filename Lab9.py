import random
import matplotlib.pyplot as plt
import matplotlib.animation as anim


def swap(A, i, j):
    a = A[j]
    A[j] = A[i]
    A[i] = a
    # also in python A[i],A[j]=A[j],A[i]


def cocktail_shaker_sort(nums):
    if (len(nums) == 1):
        return
    for i in range(len(nums)-1, 0, -1):
        
        for j in range(i, 0, -1):
            if nums[j] < nums[j-1]:
                nums[j], nums[j-1] = nums[j-1], nums[j]
                yield nums

        for j in range(i):
            if nums[j] > nums[j+1]:
                nums[j], nums[j+1] = nums[j+1], nums[j]
                yield nums
        
            


n = int(input("Enter the number of elements:"))
al = int(input("Choose algorithm:  1.Cocktail sort \n"))
array = [i + 1 for i in range(n)]
random.shuffle(array)

if (al == 1):
    title = "Cocktail Sort"
    algo = cocktail_shaker_sort(array)  
# Initialize fig
fig, ax = plt.subplots()
ax.set_title(title)

bar_rec = ax.bar(range(len(array)), array, align='edge')

ax.set_xlim(0, n)
ax.set_ylim(0, int(n * 1.1))

text = ax.text(0.02, 0.95, "", transform=ax.transAxes)

epochs = [0]


def update_plot(array, rec, epochs):
    for rec, val in zip(rec, array):
        rec.set_height(val)
    epochs[0]+= 1
    text.set_text("No.of operations :{}".format(epochs[0]))


anima = anim.FuncAnimation(fig, func=update_plot, fargs=(bar_rec, epochs), frames=algo, interval=1, repeat=False)
plt.show()
