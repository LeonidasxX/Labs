import torch
import numpy as np

tensor = torch.tensor([[
    [1,1,1],[2,2,2],[3,3,3],[4,4,4],[5,5,5],[6,6,6]
]])
print(tensor.ndim)
print(tensor.shape)
print(tensor)

# 1. Reshaping, Viewing, Stacking, Squeezing, Unsqueezing
print("Reshaping")
print(tensor.reshape(3,6))

print("Viewing")
x = tensor.view(18)
print(x)

print("Stacking")
x = torch.stack((torch.tensor([1,2,3]), torch.tensor([4,5,6])))
print(x)

print("Squeezing")
x = torch.zeros(2,1,2,1,2)
print(x.size())
y = torch.squeeze(x)
print(y.size())
y = torch.squeeze(x,3)
print(y.size())

print("Unsqueezing")
x = torch.zeros(2,2)
print(x)
print(torch.unsqueeze(x,0))

# 2. torch.permute
print("Permute")
y = torch.permute(tensor,dims=(1,2,0))
print(y)

# 3. Indexing
print("Indexing")
print(tensor[0])
print(tensor[0][1])
print(tensor[0][0][0])

# 4. Converting to NumPy arrays and back to tensor
print("Converting to numpy and then back to tensor")
x = torch.tensor([[1,1,1],[1,1,1]])
print(x)
num = np.array(x)
print(num)
num = num.reshape(3,2)
y = torch.tensor(num)
print(y)

# 5. random tensor
print("Random Tensor")
random = torch.rand((7,7))
print(random)

# 6. Mat Mul
rand_2 = torch.rand(1,7)
print("Tensor 2 for multiplication: ")
print(rand_2)
mul = random @ rand_2.T
print("After multiplication: ")
print(mul)

# 7. sending to gpu

print(torch.cuda.is_available())
device = "cuda" if torch.cuda.is_available() else "cpu"
print("Device: ", device)
print("Count of device: ", torch.cuda.device_count())

a = torch.rand((2,3))
b = torch.rand((2,3))
print("On device")
print(a, a.device)
print(b, b.device)
print("Moving to GPU")
a_gpu = a.to(device)
print(a_gpu)
b_gpu = b.to(device)
print(b_gpu)

# 8. matMul for 6
x = torch.transpose(b_gpu, 0, 1)

print(x.size())
prod = torch.matmul(a_gpu,x)
print(prod)

# 9. max and min values
print("Min and Max Value")
a = torch.min(a)
print(a)
print(torch.max(a))
print(torch.min(b))
print(torch.max(b))

# 10
print("Index of Max Min values")
print(torch.argmin(a))
print(torch.argmax(a))
print(torch.argmin(b))
print(torch.argmax(b))


# 11

a = torch.rand((1,1,1,10))
b = torch.rand((10))
print(a)
print(a.size())
print(b)
print(b.size())
