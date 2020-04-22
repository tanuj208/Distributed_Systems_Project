import numpy as np
import matplotlib.pyplot as plt

N_vals = [10**4, 5*10**4, 10**5, 2*10**5]

def idea_1(P, N, m = 2147483647):
	ret_vals = []
	for n in N:
		vals =  n/P * np.log(m) + np.log(P) + np.log(m*P)
		ret_vals.append(vals)
	return ret_vals

def idea_2(P, N, m = 2147483647):
	ret_vals = []
	for n in N:
		vals =  n/P + np.log(m*n)
		ret_vals.append(vals)
	return ret_vals

def idea_3(P, N):
	ret_vals = []
	for n in N:
		vals =  n/P + P
		ret_vals.append(vals)
	return ret_vals

def idea_4(P, N):
	ret_vals = []
	for n in N:
		vals =  n/P + np.log(n)
		ret_vals.append(vals)
	return ret_vals

def make_plot(X, Y, N, title, filename):
	plt.ticklabel_format(style='sci', axis='y', scilimits=(0,0))
	for (i, y) in enumerate(Y):
		plt.plot(X, np.log(y), label = "N = {}".format(N[i]))
	plt.xlabel("Number of processes")
	plt.ylabel("Logarithm of Time complexity")
	plt.title(title)
	plt.legend()
	plt.savefig(filename)
	plt.close()

num_processes = np.arange(1,101)
idea_1_vals = idea_1(num_processes, N_vals)
idea_2_vals = idea_2(num_processes, N_vals)
idea_3_vals = idea_3(num_processes, N_vals)
idea_4_vals = idea_4(num_processes, N_vals)

make_plot(num_processes, idea_1_vals, N_vals, "Parallel LCG - Idea 1", "idea1.png")
make_plot(num_processes, idea_2_vals, N_vals, "Parallel LCG - Idea 2", "idea2.png")
make_plot(num_processes, idea_3_vals, N_vals, "Parallel LCG - Idea 3", "idea3.png")
make_plot(num_processes, idea_4_vals, N_vals, "Ecuyer's Multiple Recursive Generator", "idea4.png")
