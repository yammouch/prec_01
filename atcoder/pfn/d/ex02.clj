(defn padding-minus-a [a yofs xofs]
  (as-> a a
        (if (< xofs 0)
          (map #(concat (repeat (- xofs) ".") %) a)
          a)
        (if (< yofs 0)
          (concat (reduce #(repeat %2 %1) "."
                          [(count (first a)) (- yofs)])
                  a))))

(defn padding-minus-b [b yofs xofs]
  (as-> b b
        (if (> xofs 0)
          (map #(concat (repeat xofs ".") %) b)
          b)
        (if (> yofs 0)
          (concat (reduce #(repeat %2 %1) "."
                          [(count (first a)) yofs])
                  b))))

(defn padding-plus [a b]
  (let [[cxa cxb] (map (comp count first) [a b])
        cxd (Math/abs (- cxa cxb))
        [cya cyb] (map count [a b])
        cyd (Math/abs (- cya cyb))
        [a b] (if (< cxa cxb)
                [(map #(concat (repeat "." cxd) %) a) b]
                [a (map #(concat (repeat "." cxd) %) b)])
    (if (< cya cyb)
      [(concat a (reduce #(repeat %2 %1) "." [(count (first a)) cyd]) b]
      [a (concat b (reduce #(repeat %2 %1) "." [(count (first b)) cyd])]
      )))
 
; �p�[�c b �� [yofs xofs] �������炵�ăp�[�c a �ɏd�˂�B
(defn add-parts [a b yofs xofs]
  (let [a (padding-minus-a a yofs xofs) ; a �� - ���W�����Ɋg��
        b (padding-minus-b b yofs xofs) ; b �� - ���W�����Ɋg��
        [a b] (padding-plus a b) ; a, b �� + ���W�����Ɋg�����A�傫���𑵂���
        ]
    ; a, b �ǂ���Ƃ� "#" �̃Z������������ nil ��Ԃ��A�I���B
    ; �p�[�c���d�˂���Ȃ�A�d�˂����Ƃ� "#", "." �̍s���Ԃ��B
    ))

; ���C�����[�`��
; - �������ǂ�
; - �p�[�c A, B, C �����̍s�A����폜
; - B �̈ʒu�A������ς��Ȃ���AA �ɏd�˂�B --- (1)
; - (1) �œ���ꂽ���ꂼ��ɑ΂��AC �̌����A�ʒu���d�˂�B --- (2)
; - (1), (2) �̃��[�v�̒��ŁA�ŏ��̖ʐς�ێ����Ă����B�Ō�ɂ�����o�́B
