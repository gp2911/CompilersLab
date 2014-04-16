package myClasses;

import java.util.HashMap;
import java.util.*;
import syntaxtree.*;

/**
 * Created with IntelliJ IDEA.
 * User: GP
 * Date: 19/10/13
 * Time: 4:01 PM
 * To change this template use File | Settings | File Templates.
 */
public class ProcRegDetails {
    public String procName;
    public int argNum;
    public int stackSpaceReq;
    public int maxArgs;
    public LinkedList<Stmt> stmtList;
    public int sRegCount;
    public int spillCount;
    public Set<Temp> tempSet;
    public LinkedList<LiveRange> liveRanges;
    public int stackIndex;
    public HashMap<Temp, LinkedList<LiveRange>> tempLiveMapping;
    public HashMap<Integer, Temp> localTemps;

    public ProcRegDetails(){
        tempLiveMapping = new HashMap<Temp, LinkedList<LiveRange>>();
        argNum = 0;
        stackSpaceReq = 0;
        maxArgs = 0;
        stmtList  =new LinkedList<Stmt>();
        tempSet = new HashSet<Temp>();
        liveRanges = new LinkedList<LiveRange>();
        localTemps = new HashMap<Integer, Temp>();
        stackIndex = 0;
        sRegCount = 0;
        spillCount = 0;
    }


}
