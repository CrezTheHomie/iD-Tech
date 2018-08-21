import gym
import gym.spaces
import numpy as np

env = gym.make("Pong-v0")

print(env.action_space.n)
print(env.observation_space.shape)


