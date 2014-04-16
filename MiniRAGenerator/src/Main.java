/**
 * Created with IntelliJ IDEA.
 * User: GP
 * Date: 20/10/13
 * Time: 4:44 PM
 * To change this template use File | Settings | File Templates.
 */
import myClasses.ProcRegDetails;
//import myClasses.RegAllocater;
import myClasses.*;
import syntaxtree.*;
import visitor.*;

import java.util.HashMap;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.*;


public class Main {
    public static LinkedList<LiveRange> activeT;
    public static LinkedList<LiveRange> activeS;

    public static LinkedList<Register> tRegs;
    public static LinkedList<Register> sRegs;

    public static void linearScanTRegAlloc(ProcRegDetails myProc){
        activeT = new LinkedList<LiveRange>();
        activeT.clear();
        Iterator<LiveRange> liveIter = myProc.liveRanges.iterator();
        while(liveIter.hasNext()){
            LiveRange l = liveIter.next();
            if(!l.inSReg){
                expireOldIntervals(myProc, l);
                if(activeT.size() == 10){
                    l.inSReg = true;
//                    myProc.sRegCount++;
                }
                else{
                    int i = 0;
                    l.reg = tRegs.get(i);
                    while(l.reg.justFreed && i!=tRegs.size()-1){
                        l.reg = tRegs.get(i+1);
                        tRegs.get(i).justFreed = false;
                        i++;

                    }
                    tRegs.remove(l.reg);
                    activeT.add(l);
//                    if(Integer.parseInt(l.tmp.f1.f0.toString()) == 57){
//                        System.out.println("PPPPPPPPPPPPPP");
//                        System.out.println(l.reg.toString());
//                    }
                    Collections.sort(activeT, LiveRange.endComparator);
//                    myProc.liveRanges.remove(l);
//                    System.out.println(l.tmp.toString()+" : "+l.reg);
//                    System.out.println("ActiveT: "+ activeT.toString());
//                    System.out.println("TRegs :"+ tRegs.toString());
                }
            }
        }
    }
    public static void linearScanSRegAlloc(ProcRegDetails myProc){
        activeS = new LinkedList<LiveRange>();
        activeS.clear();
        Iterator<LiveRange> liveIter = myProc.liveRanges.iterator();
        while(liveIter.hasNext()){
            LiveRange l = liveIter.next();
            if(l.inSReg){
                expireOldIntervals(myProc, l);
                if(activeS.size() == 8){
                    spillAtInterval(myProc, l);
//                    myProc.sRegCount--;
                    myProc.spillCount++;
                }
                else{
                    int i = 0;
                    l.reg = sRegs.get(i);
                    while(l.reg.justFreed){
                        l.reg = sRegs.get(i+1);
                        sRegs.get(i).justFreed = false;
                        i++;
                    }
                    sRegs.remove(l.reg);
                    activeS.add(l);
                    Collections.sort(activeS,LiveRange.endComparator);
//                    myProc.liveRanges.remove(l);
                    myProc.stackIndex++;
                    myProc.sRegCount++;
//                    System.out.println(l.tmp.toString()+" : "+l.reg);
//                    System.out.println("ActiveS: "+ activeS.toString());
//                    System.out.println("SRegs :"+ sRegs.toString());

                }
            }
        }
//        System.out.println(myProc.sRegCount);
//        System.out.println(myProc.spillCount);
        if(myProc.spillCount == 0)
            myProc.stackSpaceReq = myProc.sRegCount;
        else
            myProc.stackSpaceReq = 8 + myProc.spillCount ;
    }
    public static void spillAtInterval(ProcRegDetails myProc, LiveRange l){
        LiveRange spill = activeS.getLast();
        if(spill.end.stmtIndex > l.end.stmtIndex){
            l.reg = spill.reg;
            spill.reg = new Register(18+myProc.stackIndex);
            myProc.stackIndex++;
            activeS.remove(spill);
            activeS.add(l);
            Collections.sort(activeS, LiveRange.endComparator);

        }
        else{
            l.reg = new Register(myProc.stackIndex+18);
            myProc.stackIndex++;
        }

//        System.out.println(l.tmp.toString()+" : "+l.reg);
//        System.out.println("ActiveS: "+ activeS.toString());

    }
    public static void expireOldIntervals(ProcRegDetails myProc, LiveRange l){
        LinkedList<LiveRange> myActive = (LinkedList<LiveRange>) activeT.clone();
        Iterator<LiveRange> liveIter = myActive.iterator();
        while (liveIter.hasNext()){
            LiveRange j = liveIter.next();
            if(j.end.stmtIndex >= l.start.stmtIndex)
                return;
            activeT.remove(j);
            j.reg.justFreed = true;
            tRegs.add(j.reg);
            Collections.sort(tRegs);
        }
        if(activeS == null)
            return;
        myActive = (LinkedList<LiveRange>) activeS.clone();
        liveIter = myActive.iterator();
        while (liveIter.hasNext()){
            LiveRange j = liveIter.next();
            if(j.end.stmtIndex >= l.start.stmtIndex)
                return;
            activeS.remove(j);
            j.reg.justFreed = true;
            sRegs.add(j.reg);
            Collections.sort(sRegs);
        }

    }

    public static void getLiveRanges(ProcRegDetails myProc, HashMap<Integer, Temp> tmps, ArrayList<Stmt> cjmps){
        Iterator<Temp> tmpIter = myProc.tempSet.iterator();
        Iterator<Stmt> stmtIter = myProc.stmtList.iterator();
        while (tmpIter.hasNext()){
            Temp tmp1 = tmpIter.next();
            Temp tmp = null;
            int tmpNum = Integer.parseInt(tmp1.f1.f0.toString());
            LiveRange currLiveRange = null;
            if(tmpNum < myProc.argNum){
//            if(Integer.parseInt(tmp.f1.f0.toString()) < myProc.argNum){
                tmp = myProc.localTemps.get(tmpNum);
//                System.out.println(tmp);
                currLiveRange = new LiveRange(tmp,myProc.stmtList.getFirst(), myProc.stmtList.getLast());
                currLiveRange.inSReg = true;
//                myProc.sRegCount++;
                tmp.liveRange.add(currLiveRange);
//                System.out.println("-----------------------------");
//                System.out.println("Live range : "+tmp.toString()+" "+tmp.liveRange.peekFirst().toString());
                myProc.liveRanges.add(tmp.liveRange.getLast());
                myProc.tempLiveMapping.put(tmp, tmp.liveRange);
                continue;
            }
            else
                tmp = tmps.get(tmpNum);
            stmtIter = myProc.stmtList.iterator();
            boolean conditional = false;
            while (stmtIter.hasNext()){
                Stmt s = stmtIter.next();
//                if(s.isCJmp)
//                    conditional = true;
//                if(s.isJmp)
//                    conditional = false;
                //case 1: not live in, but live out...beginning of a new live interval
                if(!s.liveIn.contains(tmp) && s.liveOut.contains(tmp)){
                    if(!tmp.isLive){
                        LiveRange currRange = new LiveRange();
                        currRange.start = s;
                        currRange.tmp = tmp;
                        currRange.lastUse = s;
                        tmp.liveRange.add(currRange);
                        tmp.isLive = true;
                    }
                    if(cjmps.contains(s))
                        conditional = true;
                    if(s.isJmp)
                        conditional = false;

                }
//                case 2: live in and live out...continuation of current live range
                if(s.liveIn.contains(tmp) && s.liveOut.contains(tmp)){
                    tmp.liveRange.getLast().lastUse = s;
                    if(cjmps.contains(s))
                        conditional = true;
                    if(s.isJmp)
                        conditional = false;


                }
                //case 3: live in, but  not live out...end of current live range
                if(s.liveIn.contains(tmp) && !s.liveOut.contains(tmp)){
//                    System.out.println(tmp.toString());
//                    System.out.println(tmp.liveRange);
//                    System.out.println(s);
                    if(!conditional){
                    tmp.liveRange.getLast().end = s;
                    tmp.liveRange.getLast().lastUse = s;
                    myProc.liveRanges.add(tmp.liveRange.getLast());
//                    System.out.println();
                    myProc.tempLiveMapping.put(tmp.liveRange.getLast().tmp, tmp.liveRange);
                    tmp.isLive = false;
                    }
//                    tmp.liveRange.add((LinkedList<Stmt>) currLiveRange.clone());
//                    currLiveRange = null;
                    if(cjmps.contains(s))
                        conditional = true;
                    if(s.isJmp)
                        conditional = false;


                }

                //case 4: not live out, not live in...dead zone
                //need not be mentioned specifically
            }


            Iterator<LiveRange> liveIter = tmp.liveRange.iterator();
            int i =0;
            while (liveIter.hasNext()){
                LiveRange l = liveIter.next();
                if(l.end == null){
                    l.end = l.lastUse;
                    myProc.liveRanges.add(tmp.liveRange.getLast());
                    myProc.tempLiveMapping.put(tmp.liveRange.getLast().tmp, tmp.liveRange);
                    tmp.isLive = false;
                }
//                System.out.println(myProc.tempLiveMapping);
                if(tmp == tmps.get(29)){
//                System.out.println(tmp);
//                System.out.println("------"+ myProc.tempLiveMapping.get(tmp).get(i).toString2());
                }
                i++;
            }
//            System.out.println(tmp.toString());
//            System.out.println(tmp.liveRange.toString());

        }
//        tmpIter = myProc.tempSet.iterator();
//        while (tmpIter.hasNext()){
//            Temp tmp = tmpIter.next();
//            System.out.println(tmp.liveRange.toString());
//        }
        Collections.sort(myProc.liveRanges);
//        System.out.println(myProc.procName);
//        System.out.println(myProc.liveRanges.toString());
//        System.out.println(myProc.tempLiveMapping);

    }

    public static void setSuccessors(LinkedList<Stmt> list, HashMap<String, Stmt> map){
        Iterator<Stmt> iterator = list.iterator();
        while (iterator.hasNext()){
            Stmt s = iterator.next();
            if(s.successors!=null){
                if(s.conditionalSuccessor != null)
                    s.successors.add(map.get(s.conditionalSuccessor.f0.toString()));
                if(list.indexOf(s) != list.size()-1 && s.isJmp == false)
                    s.successors.add(list.get(list.indexOf(s)+1));
//                System.out.println(s.toString()+" : "+s.successors.toString());
            }
        }
    }
    public static void setLiveVars(LinkedList<Stmt> list){
        Iterator<Stmt> iterator;
        int count = 0;
        boolean changed = false;
        do{
            count++;
            changed = false;
//            System.out.println("**************Iteration********");
            iterator = list.iterator();
            while (iterator.hasNext()){
                Stmt s = iterator.next();
                Set<Temp> oldLiveIn = new HashSet<Temp>(s.liveIn);
                Set<Temp> oldLiveOut = new HashSet<Temp>(s.liveOut);


                Set<Temp> use = new HashSet<Temp>(s.tempsUsed);
                Set<Temp> out = new HashSet<Temp>(s.liveOut);
                Set<Temp> def = new HashSet<Temp>(s.tempsDef);

//                System.out.println("==========" + s.tempsUsed);
//                System.out.println("$$$$$$$$$$" + s.tempsDef);


                out.removeAll(def);
                use.addAll(out);
                s.liveIn = new HashSet<Temp>(use);

                if(s.successors != null){
                    Iterator<Stmt> successorIter = s.successors.iterator();
                    while(successorIter.hasNext()){
                        Stmt succ = successorIter.next();
                        s.liveOut.addAll(succ.liveIn);
                    }
                }
//                System.out.println(oldLiveIn.toString() +" ::::::::: "+s.liveIn.toString());
//                System.out.println(oldLiveOut.toString() +" ::::::::: " + s.liveOut.toString());
                if(!oldLiveIn.equals(s.liveIn) || !oldLiveOut.equals(s.liveOut))
                    changed = true;
            }
//            System.out.println(count+" : "+changed);

        } while(changed);

        iterator = list.iterator();
        while (iterator.hasNext()){
            Stmt s = iterator.next();
//            if(s.f0!=null)
//                System.out.println(s.toString()+" : "+s.f0.choice);
//            else
//                System.out.println(s.toString());
//            if(s.isJmp){
//                System.out.println("Live In: ");
//                System.out.println(s.liveIn.toString());
//                System.out.println("Live Out: ");
//                System.out.println(s.liveOut.toString());
//                System.out.println();
//                System.out.println();
//            }
        }

    }


    public static void main(String [] args) {
        try {
            tRegs = new LinkedList<Register>();
            sRegs = new LinkedList<Register>();
            for(int i = 0; i < 10 ; i++){
                tRegs.add(new Register(i));
            }
            for(int i = 10; i < 18; i++){
                sRegs.add(new Register(i));
            }
            Collections.sort(tRegs);
            Collections.sort(sRegs);
            Node root = new microIRParser(System.in).Goal();
//            System.out.println("Program parsed successfully");
            StmtIndexer si = new StmtIndexer();
            root.accept(si);
            HashMap<String, ProcRegDetails> myProcTable = si.procRegs;
            Iterator<ProcRegDetails> iterator = myProcTable.values().iterator();
            while(iterator.hasNext()){
                ProcRegDetails myProc = iterator.next();
//                System.out.println("*****************************");
//                System.out.println(myProc.procName);
                setSuccessors(myProc.stmtList, si.labelledStmts);
            }

            iterator = myProcTable.values().iterator();
            while(iterator.hasNext()){
                ProcRegDetails myProc = iterator.next();
//                System.out.println("##############################");
//                System.out.println(myProc.procName);
                setLiveVars(myProc.stmtList);
            }

            iterator = myProcTable.values().iterator();
            while(iterator.hasNext()){
                ProcRegDetails myProc = iterator.next();
//                System.out.println("+++++++++++++++++++++++++++++++++");
//                System.out.println(myProc.procName);
                getLiveRanges(myProc, si.tmps, si.conditionalJmps);
            }

            RegisterAllocater ra = new RegisterAllocater(si.procRegs);
            root.accept(ra); // Your assignment part is invoked here.
//            System.out.println();

            iterator = myProcTable.values().iterator();
            while(iterator.hasNext()){
                ProcRegDetails myProc = iterator.next();
//                System.out.println(":::::::::::::::::::::::::::::::::::");
//                System.out.println(myProc.procName);
                tRegs.clear();
                sRegs.clear();
                for(int i = 0; i < 10 ; i++){
                    tRegs.add(new Register(i));
                }
                for(int i = 10; i < 18; i++){
                    sRegs.add(new Register(i));
                }
                Collections.sort(tRegs);
                Collections.sort(sRegs);
                linearScanTRegAlloc(myProc);
                linearScanSRegAlloc(myProc);
            }

            RAGenerator gen = new RAGenerator(ra.procRegs);
            gen.tmps = si.tmps;
            root.accept(gen);

        }
        catch (ParseException e) {
            System.out.println(e.toString());
        }
    }
}




