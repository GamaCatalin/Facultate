
# import the pygame module, so you can use it
import pickle ,pygame ,sys
from pygame.locals import *
from random import random, randint
import numpy as np
import time

# Creating some colors
BLUE  = (0, 0, 255)
GRAYBLUE = (50 ,120 ,120)
RED   = (255, 0, 0)
GREEN = (0, 200, 0)
BLACK = (0, 0, 0)
WHITE = (255, 255, 255)
GRAY = (155,155,155)

# define directions
UP = 0
DOWN = 2
LEFT = 1
RIGHT = 3

# define indexes variations
v = [[-1, 0], [1, 0], [0, 1], [0, -1]]
