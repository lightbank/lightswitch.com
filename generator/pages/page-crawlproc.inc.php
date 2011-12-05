<?php // This file is protected by copyright law and provided under license. Reverse engineering of this file is strictly prohibited.




































































































$yEmIO34570923ymOnb=687202759;$RJHEs69826050JVvAY=695129395;$AzrOr42327270zoqZk=584034546;$pQDjW89887085CNWRL=634886963;$oPCrX35317993HUOmN=629155396;$NXJvG16432495DXRIc=847808594;$gPjux36043091QtZRB=73315307;$ltFcs51962280KNHgM=584644287;$vIftD67002564ZSXav=165264282;$yzlcb38976440ZbxGL=95144043;$XDzlv60696411uyBtO=155752319;$BqkLz89974976QRKsH=628057861;$CbOLn39624634niseZ=294529419;$Nkuma47457886XTBjb=435135742;$JFnAp26287231llhns=831345581;$churU23925171gHzJM=765127686;$UyqCS43184204WEMYf=17950805;$ExQOn41876831XsjrO=868783692;$DUWyO22815551JcGPM=102095092;$TAQWy33812866MEHmL=995853760;$EYdKV77681275reAMP=334528442;$SCzVF22233276AOkjs=397087891;$tfRBA50281372HLQHY=965000855;$mDstF29638061PVZRA=321236084;$LBTyJ53115845rUBkw=245262329;$SGPgs78527222GTVJQ=19048339;$TDTxG18684692jtnOp=423062866;$yyOJL11400756aXPqQ=739274658;$eiDth59487915Wdgfa=749152466;$RMmJy30758667PyzTu=733665039;$dpEvc18025512pRIcJ=474281128;$bJvmS69100952MnjGY=251969482;$IpwPQ96797486ntDkU=847198853;$qEHgy58927612EkWFk=542937988;$hxQrG48303833Yiwqh=119655639;$QLPsp22738647TUmXp=857320557;$velAn75044556ZNRMX=539401489;$pbmCf73034058zVxsG=445867187;$cvcfS19519653mDIvH=358186401;$gwxhJ52313843oxnaj=557327881;$bGaUi84229126JVWYy=824760376;$rLPIK73078003pjMkF=442452637;$FdfyI21672973ARnKk=190873413;$GLTfW67826538LJooJ=350991455;$PsnME34351196tMKed=704275513;$Oganz59059448Bugvf=532694336;$xriQi54763794PvWAI=616716675;$MLjcW69276734lPTfJ=238311279;$iJRBO15410766Xiuan=177946899;$Mlmxj30978393PUdqg=716592285;?><?php if(!$qDot7WxFYvQPR) { ?><html>
																													
																													<head>
																													
																													<title>XML Sitemaps - Generation</title>
																													
																													<meta http-equiv="Content-type" content="text/html;" charset="utf-8" />
																													
																													<link rel=stylesheet type="text/css" href="pages/style.css">
																													
																													</head>
																													
																													<body>
																													
																													<?php } if(!defined('joeXw9f7bW7PyEcEv'))exit(); if(file_exists($fn=sMuf2pf0iKaQ.e6p6oz8D73L8)&&(time()-filemtime($fn)<10*60)){ $aJAUx_d6Kz=true; ?>
																													
																													<h4>Already in progress. Current process state is displayed:</h4>
																													
																													<?php } if(!$qDot7WxFYvQPR){ ?><div id="glog">
																													
																													Links depth: <b><span id="llevel">-</span></b>
																													
																													<br>
																													
																													Current page: <span id="cpage">-</span>
																													
																													<br>
																													
																													Pages added to sitemap: <span id="compno">-</span>
																													
																													<br>
																													
																													Pages scanned: <span id="pdone">-</span> (<span id="bdone">-</span> KB)
																													
																													<br>
																													
																													Pages left: <span id="pleft">-</span> (+ <span id="l2">-</span> queued for the next depth level)
																													
																													<br>
																													
																													Time passed: <span id="tdone">-</span>
																													
																													<br>
																													
																													Time left: <span id="tleft">-</span>
																													
																													<br>
																													
																													Memory usage: <span id="musage">-</span>
																													
																													</div>
																													
																													<div id="rlog" style="bottom:5px;position:fixed;width:100%;font-size:12px;background-color:#fff;z-index:2000;padding-top:5px;border-top:#999 1px dotted"></div>
																													
																													<script language="Javascript">
																													
																													var lastupdate = new Date();
																													
																													function I2awUC97Luu3(id,txt)
																													
																													{
																													
																													el = document.getElementById(id);
																													
																													el.innerHTML = txt;
																													
																													}
																													
																													function gD2gJih5je9Dh(txt1,txt2,txt3,txt4,txt5,txt6,txt7,txt8,txt9,txt10)
																													
																													{
																													
																													I2awUC97Luu3('cpage',txt1);
																													
																													I2awUC97Luu3('pleft',txt2);
																													
																													I2awUC97Luu3('pdone',txt3);
																													
																													I2awUC97Luu3('bdone',txt4);
																													
																													I2awUC97Luu3('tdone',txt5);
																													
																													I2awUC97Luu3('tleft',txt6);
																													
																													I2awUC97Luu3('llevel',txt7);
																													
																													I2awUC97Luu3('musage',txt8);
																													
																													I2awUC97Luu3('compno',txt9);
																													
																													I2awUC97Luu3('l2',txt10);
																													
																													}
																													
																													function fusptGcMPKLg4lcD()
																													
																													{
																													
																													var cd = new Date();
																													
																													var re = document.getElementById('rlog');
																													
																													var df = (cd - lastupdate)/1000;
																													
																													re.innerHTML = 'Auto-restart monitoring: '+ cd + ' (' + Math.round(df) + ' second(s) since last update)';
																													
																													<?php if($grab_parameters['xs_autoresume']){?>
																													
																													if(df >= <?php echo $grab_parameters['xs_autoresume'];?>)
																													
																													if(window.parent && window.parent.document)
																													
																													{
																													
																													var rle = window.parent.document.getElementById('runlog');
																													
																													lastupdate = cd;
																													
																													if(rle)
																													
																													{
																													
																													rle.style.display  = '';
																													
																													rle.innerHTML = cd + ': resuming generator ('+Math.round(df)+' seconds with no response)<br />' + rle.innerHTML;
																													
																													}
																													
																													var lc = document.location;
																													
																													if(lc.href.indexOf('resume=1')<0)
																													
																													lc = lc + '&resume=1';
																													
																													document.location = lc;
																													
																													}
																													
																													<?php } ?>
																													
																													}
																													
																													window.setInterval('fusptGcMPKLg4lcD()', 1000);
																													
																													</script>
																													
																													<?php	} include sEHr9E0d1xL1nk.'class.templates.inc.php'; include sEHr9E0d1xL1nk.'class.grab.inc.php'; include sEHr9E0d1xL1nk.'class.xml-creator.inc.php'; include sEHr9E0d1xL1nk.'class.gping.inc.php'; function Zggf21Qbdvn($DFJUj5XaZVoZf, $JxNdRgLqv9xDy8 = '', $Lqem3eMvsk4mB='') { global $qZN2cRANbk1N; if($Lqem3eMvsk4mB) echo '<h4>An error occured: '.$JxNdRgLqv9xDy8.'</h4>'; else echo $JxNdRgLqv9xDy8; echo ' <script> top.location = \'index.'.$qZN2cRANbk1N.'?op='.$DFJUj5XaZVoZf.($Lqem3eMvsk4mB?'&errmsg='.urlencode(substr($Lqem3eMvsk4mB,0,500)):'').'\' </script> '; exit; } if($aJAUx_d6Kz){ $rc = @ZBWGkqS6VQ71(GHJEfA2QYqwa($fn)); BDURPicA56HxjrUUp($rc); exit; } if(file_exists(sMuf2pf0iKaQ.jgYSLBDPtmpAo)) @unlink(sMuf2pf0iKaQ.jgYSLBDPtmpAo); $jwblm4pgqCSdGONbuY = $nuBa9NbmEO6RBhcW->ZoknvuUYP(array( 'initurl'=>$grab_parameters['xs_initurl'], 'progress_callback'=>'BDURPicA56HxjrUUp', 'maxpg'=>$grab_parameters['xs_max_pages'], 'bgexec'=>$_REQUEST['bg'], 'resume'=>$_REQUEST['resume'], 'maxdepth'=>$grab_parameters['xs_max_depth'], ), $urls_completed ); if($jwblm4pgqCSdGONbuY['errmsg']||$jwblm4pgqCSdGONbuY['interrupt']){ Zggf21Qbdvn('config', '', $jwblm4pgqCSdGONbuY['interrupt']?'The process has been interrupted by user':$jwblm4pgqCSdGONbuY['errmsg']); } echo '<h4>Completed</h4>Total pages indexed: '.count($urls_completed)."\n"; echo '<br>Creating sitemaps...'."\n"; if($grab_parameters['xs_chlog']) echo ' and calculating changelog...'."\n"; echo '<div id="percprog"></div>'."\n"; flush(); $J0guAv8GXYn6AN38fxM='xmlcreate.log'; $TBuKj2tXyZ_L9p_A='htmlcreate.log'; if($_REQUEST['resume']) { $G2zCcihGLQl = @ZBWGkqS6VQ71(GHJEfA2QYqwa(sMuf2pf0iKaQ.$J0guAv8GXYn6AN38fxM)); $NBx_26Cujx04fN = @ZBWGkqS6VQ71(GHJEfA2QYqwa(sMuf2pf0iKaQ.$TBuKj2tXyZ_L9p_A)); } $grab_parameters['xs_ipconnection'] = ''; if(!$G2zCcihGLQl['done'])         $jwblm4pgqCSdGONbuY = $EYyBXYy9WWbLGYL5iQ->tk3aOovNCsJ4Z( $grab_parameters, $urls_completed, $jwblm4pgqCSdGONbuY ); if($grab_parameters['xs_makehtml']) { include sEHr9E0d1xL1nk.'class.html-creator.inc.php'; } @unlink(sMuf2pf0iKaQ.$J0guAv8GXYn6AN38fxM); @unlink(sMuf2pf0iKaQ.$TBuKj2tXyZ_L9p_A); global $qcjrymCYbzs62p2m; if($qcjrymCYbzs62p2m) { $JxNdRgLqv9xDy8 = nl2br("Error writing to these files:\n". '<b>'.htmlspecialchars(implode("\n", $qcjrymCYbzs62p2m)).'</b>'."\nPlease correct files permissions and resume sitemap creation." ); Zggf21Qbdvn('config','',$JxNdRgLqv9xDy8); }else { @unlink(sMuf2pf0iKaQ.KH6aKAnNWiCYJWvf); } BDURPicA56HxjrUUp(array('flush'=>1)); if($grab_parameters['xs_gping']) $IOVrd_HyNGxshZQSHJ->itBggRphyUbnww_vK($jwblm4pgqCSdGONbuY['rinfo']); BDURPicA56HxjrUUp(array('flush'=>1)); if($grab_parameters['xs_weblog_ping']) { $KPnlaCP0s89m = $urls_completed[0]['t']; $IOVrd_HyNGxshZQSHJ->TrDtPhboaRh($grab_parameters['xs_weblog_ping'], $grab_parameters['xs_initurl'], $KPnlaCP0s89m); } BDURPicA56HxjrUUp(array('flush'=>1)); if($grab_parameters['xs_email']) { echo '<br>Sending email notification...';flush(); include sEHr9E0d1xL1nk.'class.mail.inc.php'; $I_swi1gI_aFqiP->R4_8B4Be7gefytd($jwblm4pgqCSdGONbuY); } BDURPicA56HxjrUUp(array('flush'=>1)); Zggf21Qbdvn('view','<br />Done, redirecting to sitemap view page.'); exit; function BDURPicA56HxjrUUp($JXrAUXdkHB6bEow) { global $qDot7WxFYvQPR, $vBIKyMEhBONsP, $Wo1WjLciOv3NRe, $uLOEZmKUZLfbG74, $grab_parameters; if($JXrAUXdkHB6bEow['cmd'] == 'info') { if(!$qDot7WxFYvQPR) if($uLOEZmKUZLfbG74[$JXrAUXdkHB6bEow['id']] != $JXrAUXdkHB6bEow['text']) { if($JXrAUXdkHB6bEow['text']) echo "<script>document.getElementById('".$JXrAUXdkHB6bEow['id']."').innerHTML = '".$JXrAUXdkHB6bEow['text']."';</script>"; else echo "<script>document.getElementById('".$JXrAUXdkHB6bEow['id']."').style.display = 'none';</script>"; flush(); $uLOEZmKUZLfbG74[$JXrAUXdkHB6bEow['id']] = $JXrAUXdkHB6bEow['text']; } $JXrAUXdkHB6bEow['cmd'] = 'ping'; } if($JXrAUXdkHB6bEow['cmd'] == 'ping') { if(!$qDot7WxFYvQPR) echo "<script>lastupdate = new Date();</script>";flush(); }else if(!$JXrAUXdkHB6bEow['cmd']) { list( $ctime, $BK2AXP6fR, $Il2qN32A6EeND, $pn, $tsize, $links_level, $mu, $ebJGVa__YE, $l2 ) = $JXrAUXdkHB6bEow; $a4CGTfBmhiIdgx = $pn?($Il2qN32A6EeND/$pn)*$ctime:0; $Alh4JDTF1Prz67Ib = intval(str_replace(',','',$mu)); if($qDot7WxFYvQPR) echo "$pn | $Il2qN32A6EeND | ".number_format($tsize/1024,1)." | ".hoxrmfFginIYPn($ctime). " | ".hoxrmfFginIYPn($a4CGTfBmhiIdgx)." | $links_level | $mu | $ebJGVa__YE | $l2 | ".($Alh4JDTF1Prz67Ib-$vBIKyMEhBONsP)."\n"; else echo "<script>gD2gJih5je9Dh('".addslashes($BK2AXP6fR)."', '".$Il2qN32A6EeND."', '".$pn."', '".number_format($tsize/1024,1)."', '".hoxrmfFginIYPn($ctime)."', '".hoxrmfFginIYPn($a4CGTfBmhiIdgx)."', '".$links_level."', '".$mu."', '".$ebJGVa__YE."', '".$l2."' );</script> "; } if((time()-$Wo1WjLciOv3NRe)>min(20,$grab_parameters['xs_autoresume']-5) || $JXrAUXdkHB6bEow['flush']) { $Wo1WjLciOv3NRe = time(); if(!$qDot7WxFYvQPR) echo "<!--".str_repeat('.',4096)."-->"; flush(); } $vBIKyMEhBONsP=$Alh4JDTF1Prz67Ib; flush(); } 



































































































