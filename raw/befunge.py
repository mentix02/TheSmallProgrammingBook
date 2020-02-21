#!/usr/bin/env python3
"""
A Befunge-93 interpreter written in Python.
Spec can be found at https://en.wikipedia.org/wiki/Befunge.
"""

class Pointer:

	def __init__(self):
		self.x = 0
		self.y = 0
