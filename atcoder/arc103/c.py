n = int(input())
v = [int(x) for x in input().split()]

de = {}
do = {}

for i in range(0, len(v), 2):
  if v[i] in de:
    de[v[i]] += 1
  else:
    de[v[i]] = 1
  if v[i+1] in do:
    do[v[i+1]] += 1
  else:
    do[v[i+1]] = 1

de_k, do_k = \
 [sorted(d.keys(), reverse=True, key=lambda k: d[k]) for d in [de, do]]

if de[de_k[0]] < do[do_k[0]]:
  dl   = do
  dl_k = do_k
  ds   = de
  ds_k = de_k
else:
  dl   = de
  dl_k = de_k
  ds   = do
  ds_k = do_k

n_dl = n//2 - dl[dl_k[0]]

if dl_k[0] != ds_k[0]:
  n_ds = n//2 - ds[ds_k[0]]
elif len(ds_k) <= 1:
  n_ds = ds[ds_k[0]]
else:
  n_ds = n//2 - ds[ds_k[1]]

print(n_dl + n_ds)
