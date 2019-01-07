ExtractADPCM Sounds\Frog.ACN Data\Frog.acm
ExtractADPCM Sounds\Tongue.ACN Data\Tongue.acm
ExtractADPCM Sounds\FlyGrab.ACN Data\Flygrab.acm
ExtractADPCM Sounds\Water.ACN Data\Water.acm

ExtractADPCM Sounds\move.ACN Data\move.acm
ExtractADPCM Sounds\miss.ACN Data\miss.acm
ExtractADPCM Sounds\go.ACN Data\go.acm

rem copy /b Data\move.acm+Data\go.acm+Data\miss.acm Disk\SOUNDS.BIN

PadFile 0 4608 Disk\MOVE.ACM
PadFile 0 9216 Disk\MISS.ACM
PadFile 0 13824 Disk\GO.ACM