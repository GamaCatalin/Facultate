package Repository;
import Model.ProgramState;

import java.io.IOException;
import java.util.List;

public interface IRepository {
    ProgramState getCurrentProgramState();
    List<ProgramState> getAllProgramStates();
    void addProgramState(ProgramState prgState);
    void logProgramState(ProgramState prgState) throws IOException;
    void setLogFilePath(String path);
}
