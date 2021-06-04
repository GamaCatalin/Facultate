from Domain.Drone import *



def printMenu():
    print("Do you want to use the queue or not?")
    print()
    print("1. Use queue")
    print("2. Don't use queue")
    print()

    return processCommand()

def processCommand():

    command = input()

    if(command=="1"):
        return True
    elif(command == "2"):
        return False
    else:
        print("Wrong command!\n")
        printMenu()


def ensureNoWallSpawn(e):
    x = randint(0, 19)
    y = randint(0, 19)

    pos = []

    if(e.isWall(x,y)):
        return ensureNoWallSpawn(e)
    else:
        pos.append(x)
        pos.append(y)
        return pos



# define a main function
def main():
    # we create the environment
    e = Environment()
    e.loadEnvironment("test2.map")
    # print(str(e))

    # we create the map
    m = DMap()

    # initialize the pygame module
    pygame.init()
    # load and set the logo
    logo = pygame.image.load("logo32x32.png")
    pygame.display.set_icon(logo)
    pygame.display.set_caption("drone exploration")

    # we position the drone somewhere in the area

    dronePos = ensureNoWallSpawn(e)

    timeWait = 0
    # cream drona
    d = Drone(dronePos[0], dronePos[1])

    # create a surface on screen that has the size of 800 x 480
    screen = pygame.display.set_mode((800, 400))

    screen.fill(WHITE)
    usingQueueButton = pygame.draw.rect(screen, BLUE, (150, 90, 500, 60))
    notUsingQueueButton = pygame.draw.rect(screen, GREEN , (150, 180, 500, 60));

    time05Button = pygame.draw.rect(screen, GRAYBLUE, (50, 300, 200, 60))
    time01Button = pygame.draw.rect(screen, GRAYBLUE, (300, 300, 200, 60))
    timeEmptyButton = pygame.draw.rect(screen, GRAYBLUE, (550, 300, 200, 60))

    smallfont = pygame.font.SysFont('Arial', 35)
    smallerfont = pygame.font.SysFont('Arial', 20)

    usingQText = smallfont.render("DFS drone",True,WHITE)
    notUsingQText = smallfont.render("Smart (kinda not) drone",True,WHITE)
    time05Text = smallerfont.render("0.5 seconds per frame",True,WHITE)
    time01Text = smallerfont.render("0.1 seconds per frame",True,WHITE)
    timeEmptyText = smallerfont.render("no delay per frame",True,WHITE)


    timeRectangle = pygame.draw.rect(screen, GRAY, (20, 20, 200, 60))

    timeWaitText = smallerfont.render("time delay per frame: " + str(timeWait),True,WHITE)

    notChosenYet = True
    usingQueue = True


    while notChosenYet:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                return False

            if event.type == pygame.MOUSEBUTTONDOWN:
                mouse_pos = event.pos

                if usingQueueButton.collidepoint(mouse_pos):
                    notChosenYet=False
                    usingQueue = True
                if notUsingQueueButton.collidepoint(mouse_pos):
                    notChosenYet=False
                    usingQueue = False
                if(time05Button.collidepoint(mouse_pos)):
                    timeWait = 0.5
                if (time01Button.collidepoint(mouse_pos)):
                    timeWait = 0.1
                if (timeEmptyButton.collidepoint(mouse_pos)):
                    timeWait = 0



        usingQueueButton = pygame.draw.rect(screen, BLUE, (150, 90, 100, 50))
        notUsingQueueButton = pygame.draw.rect(screen, GREEN, (150, 180, 100, 50))
        time05Button = pygame.draw.rect(screen, GRAYBLUE, (50, 300, 200, 60))
        time01Button = pygame.draw.rect(screen, GRAYBLUE, (300, 300, 200, 60))
        timeEmptyButton = pygame.draw.rect(screen, GRAYBLUE, (550, 300, 200, 60))

        timeRectangle = pygame.draw.rect(screen, GRAY, (20, 20, 200, 60))

        timeWaitText = smallerfont.render("time delay per frame: " + str(timeWait), True, WHITE)


        screen.blit(usingQText,(300, 90))
        screen.blit(notUsingQText, (230, 180))
        screen.blit(time05Text,(60,320))
        screen.blit(time01Text, (310, 320))
        screen.blit(timeEmptyText, (560, 320))
        screen.blit(timeWaitText,(25,25))

        pygame.display.update()



    screen.fill(WHITE)
    screen.blit(e.image(), (0, 0))

    # define a variable to control the main loop
    running = True



    pygame.display.flip()

    # main loop
    while running:
        # event handling, gets all event from the event queue
        for event in pygame.event.get():
            # only do something if the event is of type QUIT
            if event.type == pygame.QUIT:
                # change the value to False, to exit the main loop
                running = False

        m.markDetectedWalls(e, d.x, d.y)

        if(usingQueue):
            d.moveDFS(m)
        else:
            d.moveSmart(m)

        if(d.x == None and d.y == None):
            running = False
        else:
            screen.blit(m.image(d.x, d.y), (400, 0))
            pygame.display.flip()
            time.sleep(timeWait)

    # time.sleep(300)
    time.sleep(10)
    pygame.quit()


# run the main function only if this module is executed as the main script
# (if you import this as a module then nothing is executed)
if __name__ == "__main__":
    # call the main function
    main()