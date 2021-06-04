from Service import *


# define a main function
def main():
    # we create the map
    m = Map()
    # m.randomMap()
    # m.saveMap("test2.map")
    m.loadMap("test1.map")

    # initialize the pygame module
    pygame.init()
    # load and set the logo
    logo = pygame.image.load("logo32x32.png")
    pygame.display.set_icon(logo)
    pygame.display.set_caption("Path in simple environment")

    # we position the drone somewhere in the area

    x = randint(0, 19)
    y = randint(0, 19)

    while(m.surface[x][y]==1):
        x = randint(0, 19)
        y = randint(0, 19)

    startX = x
    startY = y

    # create drona

    d = Drone(x, y)

    x = randint(0, 19)
    y = randint(0, 19)

    while (m.surface[x][y] == 1):
        x = randint(0, 19)
        y = randint(0, 19)

    endX = x
    endY = y



    # create a surface on screen that has the size of 400 x 480
    screen = pygame.display.set_mode((400, 400))
    screen.fill(WHITE)

    # define a variable to control the main loop

    returnA = searchAStar(m, d, startX, startY, endX, endY)
    returnGreedy = searchGreedy(m,d,startX,startY,endX,endY)
    returnDijkstra = searchDijkstra(m,d,startX,startY,endX,endY)
    returnBFS = searchBFS(m,d,startX,startY,endX,endY)


    APath = None
    GreedyPath = None
    DijkstraPath = None
    BFSPath = None


    if returnA != None:
        print("\nA* time:       {0}\n".format(returnA[1]))
        APath = returnA[0]
        print("A*  path:      {0}\n".format(APath))
        #print("A* open length:   {0}".format(len(returnA[2])))
        #print("A* closed length: {0}".format(len(returnA[3])))
    if returnGreedy != None:
        print("\nGreedy time:   {0}\n".format(returnGreedy[1]))
        GreedyPath = returnGreedy[0]
        print("Greedy path:   {0}\n".format(GreedyPath))
        #print("Greedy open length:   {0}".format(len(returnGreedy[2])))
        #print("Greedy closed length: {0}".format(len(returnGreedy[3])))
    if returnDijkstra != None:
        print("\nDijkstra time: {0}\n".format(returnDijkstra[1]))
        DijkstraPath = returnDijkstra[0]
        print("Dijkstra path: {0}\n".format(DijkstraPath))
        #print("Dijkstra open length:   {0}".format(len(returnDijkstra[2])))
        #print("Dijkstra closed length: {0}".format(len(returnDijkstra[3])))
    if returnBFS != None:
        print("\nBFS time:      {0}\n".format(returnBFS[1]))
        BFSPath = returnBFS[0]
        print("BFS path:      {0}\n".format(BFSPath))
        #print("BFS open length:   {0}".format(len(returnBFS[2])))
        #print("BFS closed length: {0}".format(len(returnBFS[3])))


    pathCase = "Greedy"

    if(pathCase=="BFS"):
        path = BFSPath
        #m.colorSearched(returnBFS[2])
    elif(pathCase=="A*"):
        path = APath
        #m.colorSearched(returnA[2])
    elif(pathCase=="Greedy"):
        path = GreedyPath
        #m.colorSearched(returnGreedy[2])
    elif(pathCase == "Dijkstra"):
        path = DijkstraPath
        #m.colorSearched(returnDijkstra[2])
    else:
        path = None



    #print(path)

    m.markStart(startX,startY)
    m.markEnd(endX,endY)

    if(path == None):
        running = False
    else:
        running = True

    # main loop
    while running:
        # event handling, gets all event from the event queue
        for event in pygame.event.get():
            # only do something if the event is of type QUIT
            if event.type == pygame.QUIT:
                # change the value to False, to exit the main loop
                running = False

            #if event.type == KEYDOWN:
            #    d.moveKeys(m)  # this call will be erased

        if(len(path)!=0):
            d.moveByArray(path,m)
        else:
            running = False

        time.sleep(0.5)
        screen.blit(d.mapWithDrone(m.image()), (0, 0))
        pygame.display.flip()

    #path = dummysearch()
    #screen.blit(displayWithPath(m.image(), path), (0, 0))

    pygame.display.flip()
    time.sleep(5)
    pygame.quit()


# run the main function only if this module is executed as the main script
# (if you import this as a module then nothing is executed)
if __name__ == "__main__":
    # call the main function
    main()