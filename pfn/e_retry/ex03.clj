; echo aaabbccd | java clojure.main -i [this .clj file]

; Decrement nth element, increment (n-1)th element of a given vector.
; If the last element is 0, the 0 is thrown away.
(defn consume [n v]
  (as-> (update-in v [n] - 1) v
        (if (= (peek v) 0)
          (pop v)
          v)
        (if (< 0 n)
          (update-in v [(- n 1)] + 1)
          v)))

; perm: �����������׍���Ȃ���������߂�B
; ��1����:
;  exclude �̗��B�ŏ��̕����̌�₩��exc��o��������̂̓�1�����O����ꍇ���w��B
;  0���w�肷��ƁA�ŏ��̕����ɐ����^���Ȃ��B
; ��2����:
;  ��n�v�f��n��o�����镶���̐���\���B
;  [n1 n2 n3] �́A1��o�����镶���� n1 �A2��o�����镶���� n2 �A
;  3��o�����镶���� n3 �ł��邱�Ƃ��Ӗ�����B
;  �Ⴆ�΁A������"aaaabbccd"�ɑ΂��Ă��̈�����[1 2 0 1]�ƂȂ�B

; �A���S���Y��: �ȉ��A(perm n [n1 n2 n3]) �� p(n, [n1, n2, n3]) �ƕ\���B
;  (A) p(0, [n1, n2, n3]) ���l����B
;   1�����ڂ̑I�ѕ��́A
;   (1) 3��o�����镶����I�ԁBn3 = 0 �̎��� 0 �ʂ�B
;   (2) 2��o�����镶����I�ԁBn2 = 0 �̎��� 0 �ʂ�B
;   (3) 1��o�����镶����I�ԁBn1 = 0 �̎��� 0 �ʂ�B
;   ��3�ʂ�B
;   (1):
;    1�����ڂ̑I�ѕ��� n3 �ʂ�B
;    2�����ڈȍ~�̕��ו��́A1�����ڂɎg���Ă��Ȃ����̂��ŏ��ɑI�ԁB
;    ���Ȃ킿�A�ŏ��̕����̌�₩��c���������̒���
;    2��o��������̂�1�����O����̂ŁA
;    p(2, [n1, n2+1, n3-1]) �ʂ�B
;    ���ǁAn3*p(2, [n1, n2+1, n3-1]) ��(1)�̏ꍇ�̐��B
;   (2) �͓��l�� n2*p(1, [n1+1, n2-1, n3])�A
;   (3) �� n1*p(0, [n1-1, n2, n3])
;   �ƂȂ�B�]���āA
;     p(0, [n1, n2, n3])
;   = n3*p(2, [n1  , n2+1, n3-1])
;   + n2*p(1, [n1+1, n2-1, n3  ])
;   + n1*p(0, [n1-1, n2  , n3  ])
;   �����藧�B
;  (B) ���ɁA��1������0�Ŗ����ꍇ�̗�Ƃ���p(1, [n1, n2, n3])���l����B
;   1�����ڂ̌�₩��1��̂ݏo�����镶����1�����O����B
;    2, 3��o�����镶���Ɋւ��ẮA(A-1)(A-2)�Ɠ��l�Ȃ̂ŁA
;     p(1, [n1, n2, n3])
;   =  n3   *p(2, [n1  , n2+1, n3-1])
;   +  n2   *p(1, [n1+1, n2-1, n3  ])
;   + (n1-1)*p(0, [n1-1, n2  , n3  ])
;   �ƂȂ�B���l�ɁA
;     p(2, [n1, n2, n3])
;   =  n3   *p(2, [n1  , n2+1, n3-1])
;   + (n2-1)*p(1, [n1+1, n2-1, n3  ])
;   +  n1   *p(0, [n1-1, n2  , n3  ])
;     p(3, [n1, n2, n3])
;   = (n3-1)*p(2, [n1  , n2+1, n3-1])
;   +  n2   *p(1, [n1+1, n2-1, n3  ])
;   +  n1   *p(0, [n1-1, n2  , n3  ])
;   �ƂȂ�B
;  (C) ��{�P�[�X�Ƃ��āAp(0, [0, 0, 0]) = 1 �ł���B

; �ȉ��A���[�v��g�ޑO�̃X�P�b�`�B

;(defn perm [exc v]
;  (+ (if (= (v 0) 0)
;       0
;       (* (- (v 0) (if (= exc 1) 1 0))
;          (perm 0 (consume 0 v))))
;     (if (= (v 1) 0)
;       0
;       (* (- (v 1) (if (= exc 2) 1 0))
;          (perm 1 (consume 1 v))))
;     (if (= (v 2) 0)
;       0
;       (* (- (v 2) (if (= exc 3) 1 0))
;          (perm 2 (consume 2 v))))
;     (if ...

(def perm-memo)

(defn perm [exc v]
  (if (empty? v)
    (if (= exc 0) 1 0)
    (mod (apply + (map-indexed
                   (fn [i x]
                     (if (= x 0)
                       0
                       (* (- x (if (= exc (+ i 1)) 1 0))
                          (perm-memo i (consume i v)))))
                   v))
         1000000007)))

; �T���c���[���傫���̂ŁA�������B
(def perm-memo (memoize perm))

(println
 (perm-memo 0
  (as-> (read-line) x
        (group-by identity x)
        (map (comp count second) x)
        (let [nmax (apply max x)
              v (vec (repeat nmax 0))]
          (reduce (fn [v n] (update-in v [(- n 1)] + 1))
                  v x)))))
