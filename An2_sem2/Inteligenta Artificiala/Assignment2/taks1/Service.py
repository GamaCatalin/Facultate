from Domain import *


def searchAStar(mapM, droneD, initialX, initialY, finalX, finalY):
    # TO DO
    # implement the search function and put it in controller
    # returns a list of moves as a list of pairs [x,y]

    start_time = time.time()

    # Create lists for open nodes and closed nodes
    open = []
    closed = []

    start = (initialX, initialY)
    end = (finalX, finalY)

    # Create a start node and an goal node
    start_node = Node(start, None)
    goal_node = Node(end, None)
    # Add the start node
    open.append(start_node)

    path = None

    # Loop until the open list is empty
    while len(open) > 0:
        # Sort the open list to get the node with the lowest cost first
        open.sort()
        # Get the node with the lowest cost
        current_node = open.pop(0)
        # Add the current node to the closed list
        closed.append(current_node)

        # Check if we have reached the goal, return the path
        if current_node == goal_node:
            path = []
            while current_node != start_node:
                path.append(current_node.position)
                current_node = current_node.parent

            break

        # Unzip the current node position
        (x, y) = current_node.position
        mapM.markSearched(x, y)
        # Get neighbors
        neighbors = [(x - 1, y), (x + 1, y), (x, y - 1), (x, y + 1)]
        # Loop neighbors
        for next in neighbors:
            # Get value from map

            (xNext, yNext) = next
            if (x == 0 or x == 19 or y == 0 or y == 19):
                mapValue = 1
            else:
                mapValue = mapM.surface[xNext][yNext]

            # Check if the node is a wall
            if (mapValue == 1):
                continue
            # Create a neighbor node
            neighbor = Node(next, current_node)
            # Check if the neighbor is in the closed list
            if (neighbor in closed):
                continue
            # Generate heuristics (Manhattan distance)
            neighbor.g = neighbor.g + 1
            neighbor.h = abs(neighbor.position[0] - goal_node.position[0]) + abs(
                neighbor.position[1] - goal_node.position[1])
            neighbor.f = neighbor.g + neighbor.h
            # Check if neighbor is in open list and if it has a lower f value
            if (addToOpen(open, neighbor) == True):
                # Everything is green, add neighbor to open list
                open.append(neighbor)
    # Return None, no path is found
    return path,time.time()-start_time,open,closed


def addToOpen(open, neighbor):
    for node in open:
        if (neighbor == node and neighbor.f >= node.f):
            return False
    return True


def searchGreedy(mapM, droneD, initialX, initialY, finalX, finalY):
    # TO DO
    # implement the search function and put it in controller
    # returns a list of moves as a list of pairs [x,y]

    start_time = time.time()

    start = (initialX, initialY)
    end = (finalX, finalY)

    # Create lists for open nodes and closed nodes
    open = []
    closed = []
    # Create a start node and an goal node
    start_node = Node(start, None)
    goal_node = Node(end, None)
    # Add the start node
    open.append(start_node)

    path = None

    # Loop until the open list is empty
    while len(open) > 0:
        # Sort the open list to get the node with the lowest cost first
        open.sort()
        # Get the node with the lowest cost
        current_node = open.pop(0)
        # Add the current node to the closed list
        closed.append(current_node)

        # Check if we have reached the goal, return the path
        if current_node == goal_node:
            path = []
            while current_node != start_node:
                path.append(current_node.position)
                current_node = current_node.parent
            break


        # Unzip the current node position
        (x, y) = current_node.position
        mapM.markSearched(x, y)
        # Get neighbors
        neighbors = [(x - 1, y), (x + 1, y), (x, y - 1), (x, y + 1)]
        # Loop neighbors
        for next in neighbors:
            # Get value from map
            (xNext, yNext) = next
            if (x == 0 or x == 19 or y == 0 or y == 19):
                mapValue = 1
            else:
                mapValue = mapM.surface[xNext][yNext]
            # Check if the node is a wall
            if (mapValue == 1):
                continue
            # Create a neighbor node
            neighbor = Node(next, current_node)
            # Check if the neighbor is in the closed list
            if (neighbor in closed):
                continue
            # Generate heuristics (Manhattan distance)
            neighbor.h = abs(neighbor.position[0] - goal_node.position[0]) + abs(
                neighbor.position[1] - goal_node.position[1])
            neighbor.f = neighbor.h
            # Check if neighbor is in open list and if it has a lower f value
            if (addToOpen(open, neighbor) == True):
                # Everything is green, add neighbor to open list
                open.append(neighbor)
    # Return None, no path is found
    return path, time.time() - start_time,open,closed



def searchDijkstra(mapM, droneD, initialX, initialY, finalX, finalY):
    start_time = time.time()

    start = (initialX, initialY)
    end = (finalX, finalY)

    # Create lists for open nodes and closed nodes
    open = []
    closed = []
    # Create a start node and an goal node
    start_node = Node(start, None)
    goal_node = Node(end, None)
    # Add the start node
    open.append(start_node)

    path = None

    # Loop until the open list is empty
    while len(open) > 0:
        # Sort the open list to get the node with the lowest cost first
        open.sort()
        # Get the node with the lowest cost
        current_node = open.pop(0)
        # Add the current node to the closed list
        closed.append(current_node)

        # Check if we have reached the goal, return the path
        if current_node == goal_node:
            path = []
            while current_node != start_node:
                path.append(current_node.position)
                current_node = current_node.parent

            break


        # Unzip the current node position
        (x, y) = current_node.position
        mapM.markSearched(x, y)
        # Get neighbors
        neighbors = [(x - 1, y), (x + 1, y), (x, y - 1), (x, y + 1)]
        # Loop neighbors
        for next in neighbors:
            # Get value from map
            (xNext, yNext) = next
            if (x == 0 or x == 19 or y == 0 or y == 19):
                mapValue = 1
            else:
                mapValue = mapM.surface[xNext][yNext]
            # Check if the node is a wall
            if (mapValue == 1):
                continue
            # Create a neighbor node
            neighbor = Node(next, current_node)
            # Check if the neighbor is in the closed list
            if (neighbor in closed):
                continue
            # Generate heuristics (Manhattan distance)
            neighbor.g = neighbor.g + 1
            neighbor.f = neighbor.g
            # Check if neighbor is in open list and if it has a lower f value
            if (addToOpen(open, neighbor) == True):
                # Everything is green, add neighbor to open list
                open.append(neighbor)
    # Return None, no path is found
    return path, time.time() - start_time,open,closed


def searchBFS(mapM, droneD, initialX, initialY, finalX, finalY):
    start_time = time.time()

    start = (initialX, initialY)
    end = (finalX, finalY)

    # Create lists for open nodes and closed nodes
    open = []
    closed = []
    # Create a start node and an goal node
    start_node = Node(start, None)
    goal_node = Node(end, None)
    # Add the start node
    open.append(start_node)

    path = None

    # Loop until the open list is empty
    while len(open) > 0:
        # Sort the open list to get the node with the lowest cost first
        open.sort()
        # Get the node with the lowest cost
        current_node = open.pop(0)
        # Add the current node to the closed list
        closed.append(current_node)



        # Check if we have reached the goal, return the path
        if current_node == goal_node:
            path = []
            while current_node != start_node:
                path.append(current_node.position)
                current_node = current_node.parent
            break


        # Unzip the current node position
        (x, y) = current_node.position
        mapM.markSearched(x,y)
        # Get neighbors
        neighbors = [(x - 1, y), (x + 1, y), (x, y - 1), (x, y + 1)]
        # Loop neighbors
        for next in neighbors:
            # Get value from map
            (xNext, yNext) = next
            if (x == 0 or x == 19 or y == 0 or y == 19):
                mapValue = 1
            else:
                mapValue = mapM.surface[xNext][yNext]
            # Check if the node is a wall
            if (mapValue == 1):
                continue
            # Create a neighbor node
            neighbor = Node(next, current_node)
            # Check if the neighbor is in the closed list
            if (neighbor in closed):
                continue

            # Check if neighbor is not in open list
            if (neighbor not in open):
                # Everything is green, add neighbor to open list
                open.append(neighbor)
    # Return None, no path is found
    return path,time.time()-start_time,open,closed




def dummysearch():
    # example of some path in test1.map from [5,7] to [7,11]
    return [[5, 7], [5, 8], [5, 9], [5, 10], [5, 11], [6, 11], [7, 11]]


def displayWithPath(image, path):
    mark = pygame.Surface((20, 20))
    mark.fill(GREEN)
    for move in path:
        image.blit(mark, (move[1] * 20, move[0] * 20))

    return image
