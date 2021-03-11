package Repository;
import Model.*;

import java.io.*;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.ArrayList;
import java.util.List;

public class RepositoryMemory implements IRepository{

    private List<ProgramState> programStates;
    private int index;
    private String logFilePath="";

    public RepositoryMemory(){
        this.programStates = new ArrayList<>();
        this.index=0;
    }

    @Override
    public ProgramState getCurrentProgramState() {
        return this.programStates.get(this.index);
    }

    @Override
    public List<ProgramState> getAllProgramStates() {
        return this.programStates;
    }

    @Override
    public void setProgramStates(List<ProgramState> programStates) {
        this.programStates = programStates;
    }

    @Override
    public void addProgramState(ProgramState prgState) {
        this.programStates.add(prgState);
    }

    @Override
    public void logProgramState(ProgramState prgState) throws IOException {
        String filePath;
        LocalDateTime currentTime = LocalDateTime.now();
        String timeString = currentTime.format(DateTimeFormatter.ofPattern("MMM-d @ hh:mm:ss.SS"));
        String basePath = "Toy Language/resources/logs/";

        if(!this.logFilePath.equals("")) {
            filePath = basePath + this.logFilePath;
            try(PrintWriter logFile = new PrintWriter(new BufferedWriter(new FileWriter(filePath,true)))) {
                logFile.print("Thread ID: "+prgState.getId());
                logFile.println("\n");
                logFile.println(timeString);
                logFile.println("\n");
                logFile.println(prgState.toString() + "\n");
                logFile.println("\n");
                logFile.println("-------------------------------------------------------------------------");
            }
        }
        else {
            filePath = basePath+timeString+".txt";
            try(PrintWriter logFile = new PrintWriter(new BufferedWriter(new FileWriter(filePath,true)))) {
                logFile.println(prgState.toString() + "\n");
            }
        }
    }


    public void setLogFilePath(String logFilePath){
        this.logFilePath=logFilePath;
    }

    public void nextState(){
        if(this.index == this.programStates.size()){
            this.index=0;
            return;
        }
        this.index++;
    }
}
