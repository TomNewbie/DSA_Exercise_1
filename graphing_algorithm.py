import matplotlib.pyplot as plt
import numpy as np
import csv

#Open the file as read and close it after completing the process
with open('result.csv', mode ='r') as file:
    draft=[]
    #Read data from the file
    sample = csv.reader(file)
    for lines in sample:
        #Append each line to the variable. The final list will appear as a 2D array of string-type element
        draft.append(lines)

draft = np.array(draft) #Convert the list to an actual 2D array so that it can be sliced conveniently by integrated array-slicing method from numpy

#Take the first row of 2D array and separate out the first element of the array, make each piece a 1D array
#Convert each element in the array to float-type variable and append back to the list
x=([float(i) for i in draft[0][1:]])
y=([float(i) for i in draft[1][1:]])
z=([float(i) for i in draft[2][1:]])
t=([float(i) for i in draft[3][1:]])

plt.figure(figsize=(50, 10)) #Set out size of the figure

plt.scatter(x, y) ; plt.scatter(x, z) ; plt.scatter(x, t) #Map out all points of all 3 data sets

#Plot the points altogether
plt.plot(x, y, label='Quick Sort', color="black")
plt.plot(x, z, label='Merge Sort', color="brown")
plt.plot(x, t, label='Insertion Sort', color="blue") 

#Label the x-axis and y-axis
plt.xlabel('n value') ; plt.ylabel('Average time executed (ms)')

#Label the general graph
plt.title("Graph of executed time by 3 sorting algorithms")

#Customize the grid so that the axis are divided into 10 parts
plt.xticks(np.arange(0,10100,1000), np.arange(0,10100,1000))

#Show legend for each plot of data set, the grid and the final graphing
plt.legend() ; plt.grid(True) ; plt.show()
