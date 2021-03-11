;5. Return the level (depth) of a node in a tree of type (1). The level of the root element is 0

;(A 2 B 0 C 2 D 0 E 0)


;nodeDepth(x:element, currentNode:element, level:int, children:int, l:list)
;    -[],sizeof(l) = 0
;    -level, x = currentNode
;    -l, children = 0
;    -nodeDepth(x, currentNode, level, (children-1), (nodeDepth(x, l1, (level+1), l2, (l3..ln)))), otherwise




(defun explore (x currentNode level children l)
        (cond
            ((eq x currentNode) (return-from explore level))
            ((null l) nil)
            ((= children 0) l)
            (t (explore x currentNode level (- children 1) (explore x (car l) (+ level 1) (cadr l) (cddr l))))
        )
)

(defun nodeDepth (x l)
    (explore x (car l) 0 (cadr l) (cddr l))
)



(print
 (nodeDepth 'S '(A 2 B 0 C 2 D 0 E 0))
)