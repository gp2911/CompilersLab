package myClasses;

import java.util.Comparator;
import java.util.LinkedList;
import syntaxtree.*;

/**
 * Created with IntelliJ IDEA.
 * User: GP
 * Date: 22/10/13
 * Time: 10:51 PM
 * To change this template use File | Settings | File Templates.
 */
public class LiveRange implements Comparable<LiveRange>{
    public Temp tmp;
    public Stmt start;
    public Stmt end;
    public boolean inSReg;
    public Register reg;
    public Stmt lastUse;

    public String toString(){
        if(reg != null)
            return tmp.toString()+" : "+inSReg+" : "+reg.toString();
        else
            return tmp.toString()+" : "+inSReg+" : undefinedReg";
    }
    public String toString2(){
        return tmp.toString()+" : "+start.stmtIndex+" : "+end.stmtIndex;
    }
    public String toString1(){
        if(reg != null)
            return tmp.toString()+" : "+start.stmtIndex+" : "+end.stmtIndex+" : "+inSReg+" : "+reg.toString();
        else if (end != null){
            return tmp.toString()+" : "+start.stmtIndex+" : "+end.stmtIndex+" : "+inSReg+" : undefinedReg";
        }
        else
            return tmp.toString()+" : "+start.stmtIndex+" : incomplete interval : "+inSReg+" : undefinedReg";
    }
    public LiveRange(){
        tmp = null;
        start = null;
        end = null;
        inSReg = false;
        reg = null;
        lastUse = null;

    }
    public LiveRange(Temp t, Stmt s1, Stmt s2){
        tmp = t;
        start = s1;
        end = s2;
        inSReg = false;
        lastUse = null;
        reg = null;
    }
    public int compareTo(LiveRange l){
        return (this.start.stmtIndex - l.start.stmtIndex);
    }

    public static Comparator<LiveRange> endComparator = new Comparator<LiveRange>() {
        @Override
        public int compare(LiveRange o1, LiveRange o2) {
            return o1.end.stmtIndex - o2.end.stmtIndex;
        }
    };
}
