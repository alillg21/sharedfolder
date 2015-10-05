mkdir -p /app/lpg
rm -rf /app/lpg/LPG
rm -rf /usr/DownloadConfig/app.lpg.LPG.cfg
rm -rf /usr/lib/libkfsdk.so
cp LPG /app/lpg/LPG
cp app.lpg.LPG.cfg /usr/DownloadConfig/app.lpg.LPG.cfg
cp libkfsdk.so /usr/lib/libkfsdk.so
cd /app/lpg/
chmod +x LPG
