# -*- coding: utf-8 -*-
from ranges import *

"""
In this file your task is to write the solver function!

"""


def solver(t, w):
    """
    Parameters
    ----------
    t : TYPE: float
        DESCRIPTION: the angle theta
    w : TYPE: float
        DESCRIPTION: the angular speed omega

    Returns
    -------
    F : TYPE: float
        DESCRIPTION: the force that must be applied to the cart
    or
    
    None :if we have a division by zero

    """

    thetaValues = getThetaValues(t)

    omegaValues = getOmegaValues(w)


    forceRange = {}

    for i in force.keys():
        forceRange[i] = 0

    for i in thetaValues.items():
        for j in omegaValues.items():
            maxValue = min(i[1], j[1])
            forceKey = fuzzyTable[i[0]][j[0]]
            if forceRange.get(forceKey) < maxValue:
                forceRange[forceKey] = maxValue


    return getForceAverage(forceRange)


def calculateTriangle(x, left, right, mean=None):
    """

    Parameters
    ----------
    x : value
    left -> a
    right -> c
    mean -> b

    Returns
    -------
    triangle function

    a <= x < b -> {
        x-a / b-a
    }

    b <= x < c -> {
        c-x / c-b
    }

    else -> {
        0
    }
    """
    if mean is None:
        mean = (left + right) / 2

    if (left is not None) and left <= x < mean:
        return (x - left) / (mean - left)
    elif (right is not None) and mean <= x < right:
        return (right - x) / (right - mean)
    else:
        return 0

def getThetaValues(t):
    thetaRanges = theta.copy()

    for i in theta.items():
        left = i[1][0]
        right = i[1][1]
        if len(i[1]) == 3:
            mean = i[1][2]
        else:
            mean = None
        thetaRanges[i[0]] = calculateTriangle(t, left, right, mean)

    return thetaRanges


def getOmegaValues(w):
    omegaRanges = omega.copy()

    for i in omega.items():
        left = i[1][0]
        right = i[1][1]
        if len(i[1]) == 3:
            mean = i[1][2]
        else:
            mean = None

        omegaRanges[i[0]] = calculateTriangle(w, left, right, mean)

    return omegaRanges


def getForceAverage(forceRange):

    totalSum = 0
    totalWeight = 0

    for j in forceRange.items():
        if len(force[j[0]]) == 3:
            b = force[j[0]][2]
        else:
            b = (force[j[0]][0] + force[j[0]][1]) / 2

        weight = j[1]
        totalSum += b * weight
        totalWeight += weight

    if totalWeight == 0:
        return None
    else:
        return totalSum / totalWeight
