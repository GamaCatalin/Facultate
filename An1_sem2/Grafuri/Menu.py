from Functions import graph

def menu():
    print(80*"-")
    print(35*" "+"Menu")

    print("1. Show graph")
    print("2. Get number of vertices")
    print("3. Get number of edges")
    print("4. Parse vertices")
    print("5. Check edge")
    print("6. Get the in degree of a vertex")
    print("7. Get the out degree of a vertex")
    print("8. Parse the outbound edges of a vertex")
    print("9. Parse the inboud edges of a vertex")
    print("10. Get the endpoints of an edge by ID")
    print("11. Modify the cost of an edge")
    print("12. Add a vertex")
    print("13. Remove a vertex")
    print("14. Add an edge")
    print("15. Remove an edge")
    print("16. Write the graph to the output file")
    print("17. Read the graph from the input file")
    print("18. Create a random graph")
    print("19. Get the minimum path with BFS")
    print("20. Get the minimum walk with Ford")
    print("21. Get highest cost between 2 vertices in a DAG")
    print("22. Get the coloring")


    print()
    print("0. Exit")
    print(80*"-")


while True:
    menu()
    command=input("Enter a command: ")
    print()
    
    if command=="1":
        print(graph.printGraph())
    elif command=="2":
        print(graph.getVerticesNr())
    elif command=="3":
        print(graph.getEdgesNr())
    elif command=="4":
        print(graph.parseVertices())
    elif command=="5":
        x=input("Enter the first vertex: ")
        y=input("Enter the second vertex: ")
        if graph.checkEdge(int(x),int(y)) == True:
            print("Edge "+x+"-"+y+" is valid")
        else:
            print("Edge "+x+"-"+y+" is not valid")
    elif command=="6":
        x=int(input("Enter a vertex: "))
        print(graph.getInDegree(x))
    elif command=="7":
        x=int(input("Enter a vertex: "))
        print(graph.getOutDegree(x))
    elif command=="8":
        x=int(input("Enter a vertex: "))
        print(graph.parseOut(x))
    elif command=="9":
        x=int(input("Enter a vertex: "))
        print(graph.parseIn(x))
    elif command=="10":
        x=int(input("Enter an edge ID: "))
        endpoints=graph.getEndpoints(x)
        print(str(endpoints[0])+" - "+str(endpoints[1]))
    elif command=="11":
        x=int(input("Enter an edge: "))
        n=int(input("Enter a new cost: "))
        graph.changeCost(x,n)
    elif command=="12":
        x=int(input("Enter a vertex: "))
        if (graph.checkVertex(x)==False):
            graph.addVertex(x)
        else:
            print("Vertex already in graph!")
    elif command=="13":
        x=int(input("Enter a vertex: "))
        if (graph.checkVertex(x)==True):
            graph.removeVertex(x)
        else:
            print("Vertex not in graph!")
    elif command=="14":
        x=int(input("Enter the first vertex: "))
        y=int(input("Enter the second vertex: "))
        cost=int(input("Enter a cost: "))
        if graph.checkEdge(x,y)==False:
            graph.addEdge(x,y,cost)
        else:
            print("Edge already exists!")
    elif command=="15":
        x=int(input("Enter the edge ID you want to remove:"))
        if graph.checkEdgeID(x)==False:
            graph.removeEdge(x)
        else:
            print("Edge does not exist!")
    elif command=="16":
        graph.writeGraph()
    elif command=="17":
        graph.readGraph()
    elif command=="18":
        x=int(input("Enter the number of vertices: "))
        y=int(input("Enter the number of edges: "))
        if (y>x*x):
            print("Can't generate this graph!\n")
        else:
            graph.generateRandom(x,y)
    elif command=="19":
        x=int(input("Enter the first vertex: "))
        y=int(input("Enter the second vertex: "))
        print(graph.breadthFirstSearch_minPath(x,y))
    elif command=="20":
        x=int(input("Enter the first vertex: "))
        y=int(input("Enter the second vertex: "))
        graph.lowestCostWalkFord(x,y)
    elif command=="21":
        x=int(input("Enter the first vertex: "))
        y=int(input("Enter the second vertex: "))
        graph.checkIfDAG(x,y)
    elif command=="22":
        graph.coloring()

    elif command=="0":
        break
    else:
        print("Invalid command!")
        print()