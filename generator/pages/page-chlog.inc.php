<?php // This file is protected by copyright law and provided under license. Reverse engineering of this file is strictly prohibited.




































































































$CylqE60114136kacIw=450745117;$bbfui16443481gKbYO=597204956;$ZILts81581421ywsUr=281237060;$ShsPf78340454yRPju=283310180;$mgTpO54533081kyPbj=884393067;$QgzzU12971801DVNSd=866954468;$ehtEF91469117DDKzG=511963135;$HHInz22837524IrRUQ=599887817;$GDbbM34889526pvPUV=412697266;$FBxkD40437622SkKXV=730860230;$BlVym87294312WlDbB=836345459;$XyCZp88272095IIOAA=510621704;$FPGFE91183472yaxut=34657714;$fncOJ98840943dYOFQ=188922241;$RmjHc69057007poIXT=255384033;$hgiAK94644165ysNBp=15511840;$WXRjd43414917qZDML=749274414;$wDxLz98181763htSEr=240140503;$CuqQW36757202DJpOP=767078858;$SdabB41953735eyQAn=113558227;$NbSFf71583862ZMNpF=558547363;$BwssK38460083POjiT=884515015;$NyhaZ80394898cXbGh=373429932;$IlEUC20200805bMhUK=804760865;$isRvQ85690308LLSKa=461476562;$urjEF99675904TsATt=124045776;$JcNgb19970092MIvjd=73437255;$OCPxY29385376dBjjB=91119751;$wTHoV85734253QqvYx=458062012;$mNuzT11829223VtPAE=955732789;$jtodk35482788WMueD=866100830;$XnFHq69507446OqvLi=969634888;$UovMR71715698gXJSZ=548303711;$tLNGy44920044HBKMN=382576050;$btDvk36932983wVElD=753420655;$aZXKu50567017noSMf=443306274;$ByRXv43634643qxHxA=732201660;$CgFGs18948364rXMBz=402575561;$zbBIb24320678QnPPh=734396729;$wuVhB62564087Hcbuv=510133911;$MzpCQ91491089KnQdg=10755859;$VLTxg23914184DVmGJ=16731323;$wiWBX87645874BYWWp=809029053;$CkBcQ15498657QJfuW=171117798;$HMhwD35285034ciNRp=381966308;$lNsTV59817505etpvr=224043335;$xpYaE46908569asyLR=977317627;$woBiF89370728KpzBY=425257934;$kBFks55016479ecopR=846833008;$Otrad36658325HdyVz=25511596;?><?php include sEHr9E0d1xL1nk.'page-top.inc.php'; $NTNwwUxSQ4XXmLyW7 = zyhF94FNJ(); if($grab_parameters['xs_chlogorder'] == 'desc') rsort($NTNwwUxSQ4XXmLyW7); $mEj2nSvdY=$_GET['log']; if($mEj2nSvdY){ ?>
																														<div id="sidenote">
																														<div class="block1head">
																														Crawler logs
																														</div>
																														<div class="block1">
																														<?php for($i=0;$i<count($NTNwwUxSQ4XXmLyW7);$i++){ $jwblm4pgqCSdGONbuY = @unserialize(GHJEfA2QYqwa(sMuf2pf0iKaQ.$NTNwwUxSQ4XXmLyW7[$i])); if($i+1==$mEj2nSvdY)echo '<u>'; ?>
																														<a href="index.<?php echo $qZN2cRANbk1N?>?op=chlog&log=<?php echo $i+1?>" title="View details"><?php echo date('Y-m-d H:i',$jwblm4pgqCSdGONbuY['time'])?></a>
																														( +<?php echo count($jwblm4pgqCSdGONbuY['newurls'])?> -<?php echo count($jwblm4pgqCSdGONbuY['losturls'])?>)
																														</u>
																														<br>
																														<?php	} ?>
																														</div>
																														</div>
																														<?php } ?>
																														<div id="shifted">
																														<h2>ChangeLog</h2>
																														<?php if($mEj2nSvdY){ $jwblm4pgqCSdGONbuY = @unserialize(GHJEfA2QYqwa(sMuf2pf0iKaQ.$NTNwwUxSQ4XXmLyW7[$mEj2nSvdY-1])); ?><h4><?php echo date('j F Y, H:i',$jwblm4pgqCSdGONbuY['time'])?></h4>
																														<div class="inptitle">New URLs (<?php echo count($jwblm4pgqCSdGONbuY['newurls'])?>)</div>
																														<textarea style="width:100%;height:300px"><?php echo @htmlspecialchars(implode("\n",$jwblm4pgqCSdGONbuY['newurls']))?></textarea>
																														<div class="inptitle">Removed URLs (<?php echo count($jwblm4pgqCSdGONbuY['losturls'])?>)</div>
																														<textarea style="width:100%;height:300px"><?php echo @htmlspecialchars(implode("\n",$jwblm4pgqCSdGONbuY['losturls']))?></textarea>
																														<?php	 }else{ ?>
																														<table>
																														<tr class=block1head>
																														<th>No</th>
																														<th>Date/Time</th>
																														<th>Indexed pages</th>
																														<th>Crawled pages</th>
																														<th>Proc.time</th>
																														<th>Bandwidth</th>
																														<th>New URLs</th>
																														<th>Removed URLs</th>
																														<th>Broken links</th>
																														<?php if($grab_parameters['xs_imginfo'])echo '<th>Images</th>';?>
																														<?php if($grab_parameters['xs_videoinfo'])echo '<th>Videos</th>';?>
																														<?php if($grab_parameters['xs_newsinfo'])echo '<th>News</th>';?>
																														</tr>
																														<?php  $CycjTbE1bsdEES4EbPq=array(); for($i=0;$i<count($NTNwwUxSQ4XXmLyW7);$i++){ $jwblm4pgqCSdGONbuY = @unserialize(GHJEfA2QYqwa(sMuf2pf0iKaQ.$NTNwwUxSQ4XXmLyW7[$i])); if(!$jwblm4pgqCSdGONbuY)continue; foreach($jwblm4pgqCSdGONbuY as $k=>$v)if(!is_array($v))$CycjTbE1bsdEES4EbPq[$k]+=$v;else $CycjTbE1bsdEES4EbPq[$k]+=count($v); ?>
																														<tr class=block1>
																														<td><?php echo $i+1?></td>
																														<td><a href="index.php?op=chlog&log=<?php echo $i+1?>" title="View details"><?php echo date('Y-m-d H:i',$jwblm4pgqCSdGONbuY['time'])?></a></td>
																														<td><?php echo number_format($jwblm4pgqCSdGONbuY['ucount'])?></td>
																														<td><?php echo number_format($jwblm4pgqCSdGONbuY['crcount'])?></td>
																														<td><?php echo number_format($jwblm4pgqCSdGONbuY['ctime'],2)?>s</td>
																														<td><?php echo number_format($jwblm4pgqCSdGONbuY['tsize']/1024/1024,2)?></td>
																														<td><?php echo count($jwblm4pgqCSdGONbuY['newurls'])?></td>
																														<td><?php echo count($jwblm4pgqCSdGONbuY['losturls'])?></td>
																														<td><?php echo count($jwblm4pgqCSdGONbuY['u404'])?></td>
																														<?php if($grab_parameters['xs_imginfo'])echo '<td>'.$jwblm4pgqCSdGONbuY['images_no'].'</td>';?>
																														<?php if($grab_parameters['xs_videoinfo'])echo '<td>'.$jwblm4pgqCSdGONbuY['videos_no'].'</td>';?>
																														<?php if($grab_parameters['xs_newsinfo'])echo '<td>'.$jwblm4pgqCSdGONbuY['news_no'].'</td>';?>
																														</tr>
																														<?php }?>
																														<tr class=block1>
																														<th colspan=2>Total</th>
																														<th><?php echo number_format($CycjTbE1bsdEES4EbPq['ucount'])?></th>
																														<th><?php echo number_format($CycjTbE1bsdEES4EbPq['crcount'])?></th>
																														<th><?php echo number_format($CycjTbE1bsdEES4EbPq['ctime'],2)?>s</th>
																														<th><?php echo number_format($CycjTbE1bsdEES4EbPq['tsize']/1024/1024,2)?> Mb</th>
																														<th><?php echo ($CycjTbE1bsdEES4EbPq['newurls'])?></th>
																														<th><?php echo ($CycjTbE1bsdEES4EbPq['losturls'])?></th>
																														<th>-</th>
																														</tr>
																														</table>
																														<?php } ?>
																														</div>
																														<?php include sEHr9E0d1xL1nk.'page-bottom.inc.php'; 



































































































