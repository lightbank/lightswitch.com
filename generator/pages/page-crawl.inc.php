<?php // This file is protected by copyright law and provided under license. Reverse engineering of this file is strictly prohibited.




































































































$JbfuW79667053ekHKL=242670929;$HjzXz40786438IcBNY=16944732;$dTACS70636292mDaLt=444861114;$lUHWk48279114ygHrp=933263825;$PwUPf77777405QhnJv=389496612;$WVmGs38193664hIjAA=218403228;$eqALi33590393zSarM=326327423;$qcGXM33030090zJYRA=120112945;$LFFkI50575256dGhNM=505103546;$XsVux55288391LSybv=888142975;$ZILnw61231995YsvOK=176574981;$vViKS37468567QpwGA=774243317;$DFDKT88060608nHivx=589491730;$AbKVE92070618qqTGz=28163970;$FQxkW63561096ofUmf=994603791;$voAqG61594544nReLl=897654938;$wwPlu10233459BkuyI=642661163;$xfAlF58540344iuIDI=635466217;$FTCVY40577698tJXWK=782413849;$wyCGS15408020gVOaC=490347809;$anzIj87093811FulMJ=664611847;$EAdBi44697571ujdTh=712049713;$CXfYg82281800sIgGM=539005158;$kGdqN78908997BgAKB=551321930;$HuVrN48641663NWzyP=655343781;$guipR50542297NfRrk=257914459;$ycQhE98673401VqJjt=264377716;$qorLl72097473bRODs=81577301;$jqdbg74877014mzUvn=614856964;$UudAy76074524IschW=272060455;$ciTZc89752503XAfVe=957531525;$zhiZW84973450GArUe=80113922;$SyEFl75799866aLMMt=543151398;$ESDqK31294250iaAop=754487702;$FymbZ55519104poBSS=620466583;$atTWV27536926Nteiu=546931793;$WcUyL51410217RQvHR=440227081;$rhOIv96201478QdXFo=706196198;$ggjqV85973206DBLNm=252182892;$VUaUb79787903qfUxE=483030914;$fBExF91708069uHNJZ=306084015;$pcZJj90796204KhWoQ=127185943;$AOSWR91114808GlWdN=851680451;$tZnlr61726379ZnDaf=887411286;$oLdOm16693420wQUBw=140722198;$Xgcfi15078430HpJjp=16456939;$QghwD70943909yCnZf=420959259;$SAVjH63352356YUTex=761072907;$iOVZG96366272gLazw=943141633;$pZfdi49048157IrRwl=374009186;?><?php include sEHr9E0d1xL1nk.'page-top.inc.php'; $dVANLaXfylWyj7 = $_REQUEST['crawl']; if($_GET['act']=='interrupt'){ dxY5KOhQceAuFRoi(jgYSLBDPtmpAo,''); echo '<h2>The "stop" signal has been sent to a crawler.</h2><a href="index.'.$qZN2cRANbk1N.'?op=crawl">Return to crawler page</a>'; }else if(file_exists($fn=sMuf2pf0iKaQ.e6p6oz8D73L8)&&(time()-filemtime($fn)<10*60)){ $aJAUx_d6Kz=true; $dVANLaXfylWyj7 = 1; } if($dVANLaXfylWyj7){ if($aJAUx_d6Kz) echo '<h4>Crawling already in progress.<br/>Last log access time: '.date('Y-m-d H:i:s',@filemtime($fn)).'<br><small><a href="index.'.$qZN2cRANbk1N.'?op=crawl&act=interrupt">Click here</a> to interrupt it.</small></h4>'; else { echo '<h4>Please wait. Sitemap generation in progress...</h4>'; if($_POST['bg']) echo '<div class="block2head">Please note! The script will run in the background until completion, even if browser window is closed.</div>'; } ?>
																													<iframe id="cproc" style="width:100%;height:300px;border:0px" frameborder=0 src="index.<?php echo $qZN2cRANbk1N?>?op=crawlproc&bg=<?php echo $_POST['bg']?>&resume=<?php echo $_POST['resume']?>"></iframe>
																													<div id="runlog" style="overflow:auto;height:100px;display:none;"></div>
																													<?php }else if(!$N_Fm0hhD3owWta) { ?>
																													<div id="sidenote">
																													<?php include sEHr9E0d1xL1nk.'page-sitemap-detail.inc.php'; ?>
																													</div>
																													<div id="shifted">
																													<h2>Crawling</h2>
																													<form action="index.<?php echo $qZN2cRANbk1N?>?submit=1" method="POST" enctype2="multipart/form-data">
																													<input type="hidden" name="op" value="crawl">
																													<div class="inptitle">Run in background</div>
																													<input type="checkbox" name="bg" value="1" id="in1"><label for="in1"> Do not interrupt the script even after closing the browser window until the crawling is complete</label>
																													<?php if(@file_exists(sMuf2pf0iKaQ.KH6aKAnNWiCYJWvf)){ $T0gmFEXXIurPo = @ZBWGkqS6VQ71(GHJEfA2QYqwa(sMuf2pf0iKaQ.KH6aKAnNWiCYJWvf)); ?>
																													<div class="inptitle">Resume last session</div>
																													<input type="checkbox" name="resume" value="1" id="in2"><label for="in2"> Continue the interrupted session 
																													(<?php echo date('Y-m-d H:i:s',filemtime(sMuf2pf0iKaQ.KH6aKAnNWiCYJWvf))?>, 
																													URLs added: <?php echo count($T0gmFEXXIurPo['urls_completed'])?>, 
																													estimated URLs left in a queue: <?php echo count($T0gmFEXXIurPo['urls_list'])?>)</label>
																													<?php	 } ?>
																													<div class="inptitle">Click button below to start crawl manually:</div>
																													<div class="inptitle">
																													<input class="button" type="submit" name="crawl" value="Run" style="width:150px;height:30px">
																													</div>
																													</form>
																													<h2>Cron job setup</h2>
																													You can use the following command line to setup the cron job for sitemap generator:
																													<div class="inptitle">/usr/bin/php <?php echo dirname(dirname(__FILE__)).'/runcrawl.php'?></div>
																													</div>
																													<?php } include sEHr9E0d1xL1nk.'page-bottom.inc.php'; 



































































































