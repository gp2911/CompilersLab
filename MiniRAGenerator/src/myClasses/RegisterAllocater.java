//
// Generated by JTB 1.3.2
//
package myClasses;


import  visitor.*;
import syntaxtree.*;
import java.util.*;

/**
 * Provides default methods which visit each node in the tree in depth-first
 * order.  Your visitors may extend this class.
 */
public class RegisterAllocater<R> implements GJNoArguVisitor<R> {
    //
    // Auto class visitors--probably don't need to be overridden.
    //

    PriorityQueue<Register> regs = new PriorityQueue<Register>();
    ArrayList<Integer> currTemps = new ArrayList<Integer>();
    public HashMap<String, ProcRegDetails> procRegs = new HashMap<String, ProcRegDetails>();
    HashMap<String,Integer> labelledStmts;
    public RegisterAllocater(HashMap<String, ProcRegDetails> hashMap){
        procRegs = hashMap;
    }

    ProcRegDetails currProc = null;
    Stmt currStmt = null;
    Exp currExpr = null;

    public R visit(NodeList n) {
        R _ret=null;
        int _count=0;
        for ( Enumeration<Node> e = n.elements(); e.hasMoreElements(); ) {
            e.nextElement().accept(this);
            _count++;
        }
        return _ret;
    }

    public R visit(NodeListOptional n) {
        if ( n.present() ) {
            R _ret=null;
            int _count=0;
            for ( Enumeration<Node> e = n.elements(); e.hasMoreElements(); ) {
                e.nextElement().accept(this);
                _count++;
            }
            return _ret;
        }
        else
            return null;
    }

    public R visit(NodeOptional n) {
        if ( n.present() )
            return n.node.accept(this);
        else
            return null;
    }

    public R visit(NodeSequence n) {
        R _ret=null;
        int _count=0;
        for ( Enumeration<Node> e = n.elements(); e.hasMoreElements(); ) {
            e.nextElement().accept(this);
            _count++;
        }
        return _ret;
    }

    public R visit(NodeToken n) { return null; }

    //
    // User-generated visitor methods below
    //

    /**
     * f0 -> "MAIN"
     * f1 -> StmtList()
     * f2 -> "END"
     * f3 -> ( Procedure() )*
     * f4 -> <EOF>
     */
    public R visit(Goal n) {
//        System.out.println("------------------------SECOND PARSE-------------------------");
        for(int i = 0; i<18;i++){
            regs.add(new Register(i));
        }
        R _ret=null;
//        System.out.println(procRegs.toString());
        currProc = procRegs.get("main");
        n.f0.accept(this);
        n.f1.accept(this);
        n.f2.accept(this);
        currProc = null;
        n.f3.accept(this);
        n.f4.accept(this);
//        System.out.println("-----------------END OF SECOND PARSE---------------------");
        return _ret;
    }

    /**
     * f0 -> ( ( Label() )? Stmt() )*
     */
    public R visit(StmtList n) {
        R _ret=null;
        n.f0.accept(this);
        return _ret;
    }

    /**
     * f0 -> Label()
     * f1 -> "["
     * f2 -> IntegerLiteral()
     * f3 -> "]"
     * f4 -> StmtExp()
     */
    public R visit(Procedure n) {
        R _ret=null;

        ProcRegDetails prevProc = currProc;
//        System.out.println("new currProc created...");
        currProc = procRegs.get(n.f0.f0.toString());
//        System.out.println(currProc);
        n.f0.accept(this);
        n.f1.accept(this);
        n.f2.accept(this);
        n.f3.accept(this);
        n.f4.accept(this);

//        procRegs.put(n.f0.f0.toString(), currProc);
//        System.out.println(currProc.procName);
//        System.out.println(currProc.tempRegMapping.toString());

        currProc = prevProc;

        return _ret;
    }

    /**
     * f0 -> NoOpStmt()
     *       | ErrorStmt()
     *       | CJumpStmt()
     *       | JumpStmt()
     *       | HStoreStmt()
     *       | HLoadStmt()
     *       | MoveStmt()
     *       | PrintStmt()
     */
    public R visit(Stmt n) {
//        System.out.println("stmt");
        Stmt prevStmt = currStmt;
        currStmt = n;
        R _ret=null;
        n.f0.accept(this);
        currStmt = prevStmt;
        return _ret;
    }

    /**
     * f0 -> "NOOP"
     */
    public R visit(NoOpStmt n) {
        R _ret=null;
        n.f0.accept(this);
        return _ret;
    }

    /**
     * f0 -> "ERROR"
     */
    public R visit(ErrorStmt n) {
        R _ret=null;
        n.f0.accept(this);
        return _ret;
    }

    /**
     * f0 -> "CJUMP"
     * f1 -> Temp()
     * f2 -> Label()
     */
    public R visit(CJumpStmt n) {
        R _ret=null;
        n.f0.accept(this);
        n.f1.accept(this);
        n.f2.accept(this);
        return _ret;
    }

    /**
     * f0 -> "JUMP"
     * f1 -> Label()
     */
    public R visit(JumpStmt n) {
        R _ret=null;
        n.f0.accept(this);
        n.f1.accept(this);
        return _ret;
    }

    /**
     * f0 -> "HSTORE"
     * f1 -> Temp()
     * f2 -> IntegerLiteral()
     * f3 -> Temp()
     *
     * TMP1[i] = TMP2;
     */
    public R visit(HStoreStmt n) {
        R _ret=null;

//        int tmp1 = Integer.parseInt(n.f1.f1.f0.toString());
//        int tmp2 = Integer.parseInt(n.f3.f1.f0.toString());

//        This is for allocating regs on the fly. But it dint work.
//
//
//        if(!currTemps.contains((Integer) tmp2)){
//            Register r = regs.poll();
//            r.isUsed = true;
//            n.f3.regStack.push(r);
//            currProc.tempRegMapping.put(tmp2,  n.f3.regStack);
//            currTemps.add(tmp2);
//            n.f3.isLive = true;
//        }
//        else if(!currTemps.contains(tmp2)){
//            Register r = regs.poll();
//            r.isUsed = true;
//            n.f3.isLive = true;
//            n.f3.regStack.push(r);
//        }
//
//        if(!currTemps.contains((Integer) tmp1)){
//            Register r = regs.poll();
//            r.isUsed = true;
//            n.f1.regStack.push(r);
//            currProc.tempRegMapping.put(tmp1,  n.f1.regStack);
//            currTemps.add(tmp1);
//            n.f1.isLive = true;
//        }
//        else if(!currTemps.contains(tmp1)){
//            Register r = regs.poll();
//            r.isUsed = true;
//            n.f1.isLive = true;
//            n.f1.regStack.push(r);
//        }

//      I shouldnt remove tmp1 from currTemps coz only tmp1[i] is defined here
//      currTemps.remove(tmp1);

//        currStmt.tempsUsed.add(n.f1);
//        currStmt.tempsUsed.add(n.f3);

        n.f0.accept(this);
        n.f1.accept(this);
        n.f2.accept(this);
        n.f3.accept(this);
        return _ret;
    }

    /**
     * f0 -> "HLOAD"
     * f1 -> Temp()
     * f2 -> Temp()
     * f3 -> IntegerLiteral()
     *
     * TMP1 = TMP2[i];
     */
    public R visit(HLoadStmt n) {
        R _ret=null;

//        int tmp1 = Integer.parseInt(n.f1.f1.f0.toString());
//        int tmp2 = Integer.parseInt(n.f2.f1.f0.toString());

//        if(!currTemps.contains((Integer) tmp2)){
//            Register r = regs.poll();
//            r.isUsed = true;
//            n.f2.regStack.push(r);
//            currProc.tempRegMapping.put(tmp2, n.f2.regStack);
//            currTemps.add(tmp2);
//            n.f2.isLive = true;
//        }
//
//        else if(!currTemps.contains(tmp2)){
//            Register r = regs.poll();
//            r.isUsed = true;
//            n.f2.isLive = true;
//            n.f2.regStack.push(r);
//        }

//        Register r = currProc.tempRegMapping.get(tmp1).peek();
//        regs.add(r);
//        r.isUsed = false;
//        currTemps.remove((Integer)tmp1);

//        currStmt.tempsUsed.add(n.f2);
//        currStmt.tempsDef.add(n.f1);

        n.f0.accept(this);
        n.f1.accept(this);
        n.f2.accept(this);
        n.f3.accept(this);
        return _ret;
    }

    /**
     * f0 -> "MOVE"
     * f1 -> Temp()
     * f2 -> Exp()
     *
     * t = exp;
     */
    public R visit(MoveStmt n) {
        R _ret=null;

        int tmp = Integer.parseInt(n.f1.f1.f0.toString());

//        System.out.println("---------------------------------------------------");
//        System.out.println("Move stmt...");

//        System.out.println(tmp);
//        System.out.println(currProc.procName);
//        System.out.println(currProc.tempRegMapping.toString());

        n.f0.accept(this);
        n.f1.accept(this);
        n.f2.accept(this);

//        regs.add(currProc.tempRegMapping.get(tmp).peek());
//        currTemps.remove((Integer)tmp);
        currStmt.tempsDef.add(n.f1);
        currStmt.tempsUsed.addAll(n.f2.tempsUsed);

//        System.out.println(currTemps.toString());
//        System.out.println(currProc.tempRegMapping.toString());


        return _ret;


    }

    /**
     * f0 -> "PRINT"
     * f1 -> SimpleExp()
     */
    public R visit(PrintStmt n) {
        R _ret=null;

        n.f0.accept(this);
        n.f1.accept(this);

//        System.out.println("here");
//        System.out.println(n.f1.f0.which);
//        System.out.println(n.f1.info);

        if(n.f1.f0.which == 0){
            currStmt.tempsUsed.add(n.f1.info);
        }

//        if(n.f1.f0.which == 0){
//            int tmp = Integer.parseInt(n.f1.info);
//            System.out.println(tmp);
//            if(!currTemps.contains((Integer) tmp)){
//                n.f1.regs.push(regs.poll());
//                currProc.tempRegMapping.put(tmp, n.f1.regs);
//                currTemps.add(tmp);
//            }
//        }
        return _ret;
    }

    /**
     * f0 -> Call()
     *       | HAllocate()
     *       | BinOp()
     *       | SimpleExp()
     */
    public R visit(Exp n) {
        R _ret=null;
        Exp prevExpr = currExpr;
        currExpr = n;
        n.f0.accept(this);

//        System.out.println("---------------------------------------");
//        System.out.println("in Expr");
//        System.out.println(n.f0.which);
//        System.out.println(currExpr.tempsUsed.toString());
//        System.out.println(regs.toString());

//        Allocating regs fr tmps used in the exp on the fly
//        Iterator<Integer> it = currExpr.tempsUsed.iterator();
//        while(it.hasNext()){
//            int tmp = it.next();
//            Register reg = regs.poll();
//            System.out.println(tmp + " : "+reg);
//            System.out.println(regs.toString());
//            if(!currProc.tempRegMapping.containsKey(tmp)){
//                Stack<Register> regStack = new Stack<Register>();
//                regStack.push(regs.poll());
//                currProc.tempRegMapping.put(tmp, regStack);
//                currTemps.add(tmp);
//            }
//            else if(!currTemps.contains(tmp)){
//                currProc.tempRegMapping.get(tmp).push(reg);
//                currTemps.add(tmp);
//            }
//
//        }
//        System.out.println(currProc.tempRegMapping.toString());
        currExpr = prevExpr;
        return _ret;
    }

    /**
     * f0 -> "BEGIN"
     * f1 -> StmtList()
     * f2 -> "RETURN"
     * f3 -> SimpleExp()
     * f4 -> "END"
     */
    public R visit(StmtExp n) {
        R _ret=null;
//        System.out.println("STMT EXP");
        n.f0.accept(this);
        n.f1.accept(this);
        n.f2.accept(this);
        n.f3.accept(this);
        n.f4.accept(this);
        return _ret;
    }

    /**
     * f0 -> "CALL"
     * f1 -> SimpleExp()
     * f2 -> "("
     * f3 -> ( Temp() )*
     * f4 -> ")"
     */
    public R visit(Call n) {
        R _ret=null;
//        System.out.println("CALL");
        Iterator<Integer> iterator = currTemps.iterator();
        int i = 0;
//        System.out.println(currProc.procName);
        Iterator<Temp> tempIterator = currProc.tempSet.iterator();
        while(tempIterator.hasNext()){
//            System.out.println("in while 1");
            Temp t = tempIterator.next();
            Iterator<LiveRange> liveRangeIterator = t.liveRange.iterator();
            while (liveRangeIterator.hasNext()){
                LiveRange l = liveRangeIterator.next();
//                System.out.println(Integer.parseInt(l.tmp.f1.f0.toString()));
//                if(Integer.parseInt(l.tmp.f1.f0.toString()) == 20){
//                    System.out.println("∂∂∂∂∂∂∂∂∂∂∂∂∂∂∂∂∂∂∂∂∂∂∂∂∂∂∂∂∂----------------∂∂∂∂∂∂∂∂∂∂∂∂∂∂∂∂∂∂∂∂∂∂");
//                    System.out.println(l.start.stmtIndex+" : "+l.end.stmtIndex+">>>>"+ currStmt.stmtIndex);
//                }
//                System.out.println(l);
//                System.out.println(l.start+" : "+l.end);
//                System.out.println(currStmt);
                if(l.start.stmtIndex < currStmt.stmtIndex && l.end.stmtIndex > currStmt.stmtIndex){
                    l.inSReg = true;
                    i++;
                    break;
                }
            }
        }
        n.f0.accept(this);
        n.f1.accept(this);
        n.f2.accept(this);
//        System.out.println("-----------------------");
//        System.out.println("in Call");
//        System.out.println(n.f3.present());
//        System.out.println(n.f3.elements());
//        if ( n.f3.present() ) {
//            for ( Enumeration<Node> e = n.f3.elements(); e.hasMoreElements(); ) {
//                Temp t = (Temp)(e.nextElement());
//                System.out.println("****"+Integer.parseInt(t.f1.f0.toString()));
//                currExpr.tempsUsed.add(t);
//                t.accept(this);
//            }
//        }
//        else
//            return null;
        n.f4.accept(this);
        return _ret;
    }

    /**
     * f0 -> "HALLOCATE"
     * f1 -> SimpleExp()
     */
    public R visit(HAllocate n) {
        R _ret=null;
        if(n.f1.SimplexType == "temp")
            currExpr.tempsUsed.add(n.f1.info);
        n.f0.accept(this);
        n.f1.accept(this);
        return _ret;
    }

    /**
     * f0 -> Operator()
     * f1 -> Temp()
     * f2 -> SimpleExp()
     */
    public R visit(BinOp n) {
        R _ret=null;
        currExpr.tempsUsed.add(n.f1);
        n.f0.accept(this);
        n.f1.accept(this);
        n.f2.accept(this);
        if(n.f2.SimplexType == "temp")
            currExpr.tempsUsed.add(n.f2.info);
        return _ret;
    }

    /**
     * f0 -> "LT"
     *       | "PLUS"
     *       | "MINUS"
     *       | "TIMES"
     */
    public R visit(Operator n) {
        R _ret=null;
        n.f0.accept(this);
        return _ret;
    }

    /**
     * f0 -> Temp()
     *       | IntegerLiteral()
     *       | Label()
     */
    public R visit(SimpleExp n) {
        R _ret=null;
        n.f0.accept(this);
        if(n.f0.which == 0){
            n.SimplexType = "temp";
            n.info = (Temp) n.f0.accept(this);

//            int tmp = Integer.parseInt(n.info);
//            Register reg = regs.poll();
//            System.out.println(tmp + " : "+reg);
//            System.out.println(regs.toString());
//            if(!currProc.tempRegMapping.containsKey(tmp)){
//                Stack<Register> regStack = new Stack<Register>();
//                regStack.push(regs.poll());
//                currProc.tempRegMapping.put(tmp, regStack);
//                currTemps.add(tmp);
//            }
//            else if(!currTemps.contains(tmp)){
//                currProc.tempRegMapping.get(tmp).push(reg);
//                currTemps.add(tmp);
//            }
//

        }
        else if(n.f0.which == 1)
            n.SimplexType = "int";
        else
            n.SimplexType = "label";
        return _ret;
    }

    /**
     * f0 -> "TEMP"
     * f1 -> IntegerLiteral()
     */
    public R visit(Temp n) {
        R _ret=null;
        n.f0.accept(this);
        n.f1.accept(this);
//        if(!tmps.containsKey(Integer.parseInt(n.f1.f0.toString()))){
//            tmps.put(Integer.parseInt(n.f1.f0.toString()), n);
//        }
//        System.out.println("---"+ n.f1.f0.toString());
        return (R) n;
    }

    /**
     * f0 -> <INTEGER_LITERAL>
     */
    public R visit(IntegerLiteral n) {
        R _ret=null;
        n.f0.accept(this);
        return _ret;
    }

    /**
     * f0 -> <IDENTIFIER>
     */
    public R visit(Label n) {
        R _ret=null;
        n.f0.accept(this);
        return _ret;
    }

}
