while (l<r) {
  m=(l+r)/2;
  if (a[m]<k) l=m+1;
  else r = m;
}
if (a[r]==k) printf("%d", r);
else printf("-1");
