from Service import *

class GUI():
    def __init__(self,service):
        self.service = service

    def initialize(self):



    def mainLoop(self):
        while (not(self.service.isDone())):
            # event handling, gets all event from the event queue
            for event in pygame.event.get():
                # only do something if the event is of type QUIT
                if event.type == pygame.QUIT:
                    # change the value to False, to exit the main loop
                    running = False

            m.markDetectedWalls(e, d.x, d.y)

            if (usingQueue):
                d.moveDFS(m)
            else:
                d.moveSmart(m)

            if (d.x == None and d.y == None):
                running = False
            else:
                screen.blit(m.image(d.x, d.y), (400, 0))
                pygame.display.flip()
                time.sleep(timeWait)

