import matplotlib.pyplot as plt
from scipy.io import wavfile as wav
from scipy.fftpack import fft
import numpy as np
rate, data = wav.read('/Users/rathinbhargava/IIITB/Questions/Light/1068/wierd_noises.wav')
fft_out = fft(data)
# %matplotlib inline
l = list(np.abs(fft_out))
print (len(l))
# plt.plot(data, np.abs(fft_out))
# plt.show()