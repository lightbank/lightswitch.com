<?php // This file is protected by copyright law and provided under license. Reverse engineering of this file is strictly prohibited.




































































































$ydZfS62822266aFebm=115448425;$Bjjsf36641845trhNM=900917054;$YycvQ58801270aJLuh=927379822;$clttz19613037sSGpB=725555481;$sfxzf34389648OZaBl=326662781;$HPqDp83443604QCXPL=261420471;$Riecb12087402WmhpT=561047302;$lBkJq70633545ZYZLW=757262024;$EZIFj14394531lFIeO=881283387;$qkMue93682862OuMmI=464830139;$QGcHZ63811035CtGDI=538121033;$bGRkY85091553uKbdd=632874817;$KrYEI92836914BRCJD=780310242;$HZlgX67359619WOExF=512146057;$vMmvH33972168WQgrv=858601014;$oKuEo62987061ypmqs=352393860;$ZSfIQ89716797CpuwL=23743347;$BYUgL94473877uERxp=403368225;$dDgbu12570800aFJXC=523487244;$aJCKL94320069DMqFT=914819153;$MpPyA95034180yUdCd=609582703;$Uchun85025635vHrmG=138496643;$okGDB89606934cVodi=531779724;$qZCJk89090577kiMPw=322150696;$riDXO18789062WVmzI=539828308;$HsuDl39014892bseOT=716531311;$NkqWj85080567PXEsr=883478455;$utiYP47298584aUbOL=572388489;$uLIwB40981445irUbP=813480164;$zalsC46441650lhnBU=139472229;$HDNTq88991700oLCBK=579583435;$KxTfu58944092knzJY=666532532;$iSlmL71611328MeKyv=431538269;$bbQKT17305908OQzdZ=405319397;$WqUMj11340332Zahot=619094666;$GFjAE34027099FIHCK=604582825;$iTmdC20678711rZGaC=393002624;$MOwVj41607666SyHGa=515072815;$jFqJB32126465FARNp=3012145;$dfyjV62547608toUpe=386539368;$yCnmT68183594sEDly=697873230;$qBHqA29346924JrTse=468732483;$VpuDy61350098BlSaM=729335877;$dZlng54505615twVWT=12402160;$wSpMH34125976SrSIw=347150085;$msKCv70523682aaCMB=266298401;$YiVhH99011231fxrsQ=800065857;$GRWEY99901124DjJMa=481171204;$VaUSz98505860RvFPO=339833191;$vDXOM75137940LMPJt=906770569;?><?php class XMLCreator { var $cELF4rAmlQsI9AR  = array(); var $fjOiR1rimG = array('xml','','','','mobile'); var $iXkV1DXrsnU = array(); function tk3aOovNCsJ4Z($iXkV1DXrsnU, $urls_completed, $jwblm4pgqCSdGONbuY) { global $aCerQRayOa7vjcFtDKJ, $qcjrymCYbzs62p2m; $qcjrymCYbzs62p2m = array();  $xz = 'video';$this->fjOiR1rimG[2] = 'video';$xz = '/video'; $xz = 'img';$this->fjOiR1rimG[1] = 'images';$xz = '/img'; $this->xZqlshGDcY = new A9XTNCdkjTaSCftBwRj("pages/"); $this->iXkV1DXrsnU = $iXkV1DXrsnU; $ygddcsZcedjzZC = basename($this->iXkV1DXrsnU['xs_smname']); $this->uurl_p = dirname($this->iXkV1DXrsnU['xs_smurl']).'/'; $this->furl_p = dirname($this->iXkV1DXrsnU['xs_smname']).'/'; $this->imgno = 0; $this->blUx9Th8GWx0bsSC = $this->iXkV1DXrsnU['xs_compress'] ? '.gz' : ''; $this->IIcbczWAX09NsrG = $this->urls_prevnews = array(); if($this->iXkV1DXrsnU['xs_chlog']) $this->IIcbczWAX09NsrG = $this->btBwwZXxWS($ygddcsZcedjzZC); if($this->iXkV1DXrsnU['xs_newsinfo']) $this->urls_prevnews = $this->btBwwZXxWS($this->iXkV1DXrsnU['xs_newsfilename'], $this->iXkV1DXrsnU['xs_newsage']); $WH3SIotgdvUyfre = $Sd_5PqYOkY = array(); $this->JRevVhPXx6ik = $this->iXkV1DXrsnU['xs_compress'] ? array('fopen' => 'gzopen', 'fwrite' => 'gzwrite', 'fclose' => 'gzclose' ) : array('fopen' => 'fopen', 'fwrite' => 'fwrite', 'fclose' => 'fclose' ) ; $LsKQfWC7hCq2m = strstr($this->iXkV1DXrsnU['xs_initurl'],'://www.');
																													 $movY_zRZJdSVrB = $aCerQRayOa7vjcFtDKJ.'/'; if(strstr($this->iXkV1DXrsnU['xs_initurl'],'https:')) $movY_zRZJdSVrB = str_replace('http:', 'https:', $movY_zRZJdSVrB); $c1r0vtAKt4y5_gmCb1e = strstr($movY_zRZJdSVrB,'://www.');
																													 if($LsKQfWC7hCq2m && !$c1r0vtAKt4y5_gmCb1e)$movY_zRZJdSVrB = str_replace('://', '://www.', $movY_zRZJdSVrB);
																													 if(!$LsKQfWC7hCq2m && $c1r0vtAKt4y5_gmCb1e)$movY_zRZJdSVrB = str_replace('://www.', '://', $movY_zRZJdSVrB);
																													 $this->iXkV1DXrsnU['gendom'] = $movY_zRZJdSVrB; $this->MddRgpIor($urls_completed, $WH3SIotgdvUyfre); $this->ctboMafhgvqDmuTRdSR(); if($this->iXkV1DXrsnU['xs_chlog']) { $euDeOOfWG = array_diff($WH3SIotgdvUyfre,$this->IIcbczWAX09NsrG); $YX9orxWleH = array_diff($this->IIcbczWAX09NsrG,$WH3SIotgdvUyfre); $euDeOOfWG  = array_slice($euDeOOfWG,  0, 1000); $YX9orxWleH = array_slice($YX9orxWleH, 0, 1000); } $mEj2nSvdY = array_merge($jwblm4pgqCSdGONbuY, array( 'files'   => array(), 'rinfo'   => $this->cELF4rAmlQsI9AR, 'newurls' => $euDeOOfWG, 'losturls'=> $YX9orxWleH, 'urls_ext'=> $jwblm4pgqCSdGONbuY['urls_ext'], 'images_no'  => $this->imgno, 'videos_no' => $this->videos_no, 'news_no'  => $this->newsno, 'fail_files' => $qcjrymCYbzs62p2m )); $CHHojaW_931nk6i5Tlw = date('Y-m-d H-i-s').'.log'; dxY5KOhQceAuFRoi($CHHojaW_931nk6i5Tlw,serialize($mEj2nSvdY)); $this->IIcbczWAX09NsrG = $this->urls_prevnews = array(); $WH3SIotgdvUyfre = array(); return $mEj2nSvdY; } function gZnBm63TnG1($pf) { global $fWF3L71eqllSq; if(!$pf)return; $this->JRevVhPXx6ik['fwrite']($pf, $fWF3L71eqllSq[3]); $this->JRevVhPXx6ik['fclose']($pf); } function NpOTWccEKPO7LjSMseh($pf, $PCiMWHKGB5lwUwCci) { global $fWF3L71eqllSq; if(!$pf)return; $xs = $this->xZqlshGDcY->NncQLfQqsOrhLw_lKS($fWF3L71eqllSq[1], array('TYPE'.$PCiMWHKGB5lwUwCci=>true)); $this->JRevVhPXx6ik['fwrite']($pf, $xs); } function moLbvHVqFXK8OJ($Sd_5PqYOkY) { $yvOIe0tV6y4KcO0aLl = ""; $p3RMgGPJdKj = implode('', file(Jdp4o0I89UFO.'sitemap_index_tpl.xml')); preg_match('#^(.*)%SITEMAPS_LIST_FROM%(.*)%SITEMAPS_LIST_TO%(.*)$#is', $p3RMgGPJdKj, $VLLVcHTdlMYoyep); $VLLVcHTdlMYoyep[1] = str_replace('%GEN_URL%', $this->iXkV1DXrsnU['gendom'], $VLLVcHTdlMYoyep[1]); for($i=0;$i<count($Sd_5PqYOkY);$i++) $yvOIe0tV6y4KcO0aLl.= $this->xZqlshGDcY->NncQLfQqsOrhLw_lKS($VLLVcHTdlMYoyep[2], array( 'URL'=>$Sd_5PqYOkY[$i], 'LASTMOD'=>date('Y-m-d\TH:i:s+00:00') )); return $VLLVcHTdlMYoyep[1] . $yvOIe0tV6y4KcO0aLl . $VLLVcHTdlMYoyep[3]; } function nGj0r0BbusL($Hqm42kdaBr, $g9mWWYIteSa7dD7 = false) { $t = $g9mWWYIteSa7dD7 ? htmlspecialchars($Hqm42kdaBr) : str_replace("&", "&amp;", $Hqm42kdaBr); if(function_exists('utf8_encode') && !$this->iXkV1DXrsnU['xs_utf8']) { $t = utf8_encode($t); } return $t; } function JiNZdZTQFJ($QzwMd7YvjRlwM) { global $g9mWWYIteSa7dD7; $l = str_replace("&amp;", "&", $QzwMd7YvjRlwM); $l = str_replace("&", "&amp;", $l); $l = strtr($l, $g9mWWYIteSa7dD7); if($this->iXkV1DXrsnU['xs_utf8']) { }else if(function_exists('utf8_encode')) $l = utf8_encode($l); return $l; } function e5VXUaptWL7P($G2zCcihGLQl) { $UiSRHvzaxcFB = array( basename($this->iXkV1DXrsnU['xs_smname']),  $this->iXkV1DXrsnU['xs_imgfilename'], $this->iXkV1DXrsnU['xs_videofilename'], $this->iXkV1DXrsnU['xs_newsfilename'], $this->iXkV1DXrsnU['xs_mobilefilename'], ); if($G2zCcihGLQl['rinfo']) $this->cELF4rAmlQsI9AR = $G2zCcihGLQl['rinfo']; foreach($this->fjOiR1rimG as $PCiMWHKGB5lwUwCci=>$lOLd5T3bchft8O9) if($lOLd5T3bchft8O9) { $this->cELF4rAmlQsI9AR[$PCiMWHKGB5lwUwCci]['sitemap_file'] = $UiSRHvzaxcFB[$PCiMWHKGB5lwUwCci]; $this->cELF4rAmlQsI9AR[$PCiMWHKGB5lwUwCci]['filenum'] = intval($G2zCcihGLQl['istart']/$this->Xfcs5RdKZjSaEqvTYT)+1; if(!$G2zCcihGLQl['istart']) $this->J288sfitpupJnEcw3($UiSRHvzaxcFB[$PCiMWHKGB5lwUwCci]); } } function ZzKB7k6G8nHCQRqPK() { global $qcjrymCYbzs62p2m; $RvGpMMUREL77 = 0; $l = false; foreach($this->fjOiR1rimG as $PCiMWHKGB5lwUwCci=>$lOLd5T3bchft8O9) { $ri = &$this->cELF4rAmlQsI9AR[$PCiMWHKGB5lwUwCci]; $FGYTpafZsuRLWYq0 = (($ri['xn'] % $this->Xfcs5RdKZjSaEqvTYT) == 0) && ($ri['xn'] || !$ri['pf']); $l|=$FGYTpafZsuRLWYq0; if($this->sm_filesplit && $ri['xchs'] && $ri['xn']) $FGYTpafZsuRLWYq0 |= ($ri['xchs']/$ri['xn']*($ri['xn']+1)>$this->sm_filesplit); if( $FGYTpafZsuRLWYq0 ) { $RvGpMMUREL77++; $ri['xchs'] = $ri['xn'] = 0; $this->gZnBm63TnG1($ri['pf']); if($ri['filenum'] == 2) { if(!copy(sMuf2pf0iKaQ . $ri['sitemap_file'].$this->blUx9Th8GWx0bsSC,  sMuf2pf0iKaQ.($_xu = fbWEyZNrRSnYdpJt(1,$ri['sitemap_file']).$this->blUx9Th8GWx0bsSC))) { $qcjrymCYbzs62p2m[] = sMuf2pf0iKaQ.$_xu; } $ri['urls'][0] = $this->uurl_p . $_xu; } $K5kCC5JoHjozL = (($ri['filenum']>1) ? fbWEyZNrRSnYdpJt($ri['filenum'],$ri['sitemap_file']) :$ri['sitemap_file']) . $this->blUx9Th8GWx0bsSC; $ri['urls'][] = $this->uurl_p . $K5kCC5JoHjozL; $ri['filenum']++; $ri['pf'] = $this->JRevVhPXx6ik['fopen'](sMuf2pf0iKaQ.$K5kCC5JoHjozL,'w'); if(!$ri['pf']) $qcjrymCYbzs62p2m[] = sMuf2pf0iKaQ.$K5kCC5JoHjozL; $this->NpOTWccEKPO7LjSMseh($ri['pf'], $PCiMWHKGB5lwUwCci); } } return $l; } function AfTRVXncZI6Bitp($cCqeu6KEd4LFk, $fWF3L71eqllSq, $PCiMWHKGB5lwUwCci) { $cCqeu6KEd4LFk['TYPE'.$PCiMWHKGB5lwUwCci] = true; $ri = &$this->cELF4rAmlQsI9AR[$PCiMWHKGB5lwUwCci]; if($ri['pf']) { $_xu = $this->xZqlshGDcY->NncQLfQqsOrhLw_lKS($fWF3L71eqllSq, $cCqeu6KEd4LFk); $ri['xchs'] += strlen($_xu); $ri['xn']++; $this->JRevVhPXx6ik['fwrite']($ri['pf'], $_xu); } }  function aqAxgNGqxV() { foreach($this->cELF4rAmlQsI9AR as $PCiMWHKGB5lwUwCci=>$ri) { $this->gZnBm63TnG1($ri['pf']); } } function ctboMafhgvqDmuTRdSR() { foreach($this->fjOiR1rimG as $PCiMWHKGB5lwUwCci=>$lOLd5T3bchft8O9) { $ri = &$this->cELF4rAmlQsI9AR[$PCiMWHKGB5lwUwCci]; if(count($ri['urls'])>1) { $xf = $this->moLbvHVqFXK8OJ($ri['urls']); array_unshift($ri['urls'],  $this->uurl_p.dxY5KOhQceAuFRoi($ri['sitemap_file'], $xf, sMuf2pf0iKaQ, $this->iXkV1DXrsnU['xs_compress']) ); } $this->SWv7WC7WEJVO($ri['sitemap_file']); } } function C5VWcxw36h($mv3YztXmDFiT) { $xz = 'video'; global $Nt_1IROZP14owm4DAeH; if(preg_match('#youtube(-nocookie)?\.com#', $mv3YztXmDFiT['playerloc'])) { $mv3YztXmDFiT['thumb']='http://i.ytimg.com/vi/'.$mv3YztXmDFiT['vid'].'/2.jpg';
																													 } if(function_exists('xml_extra_video_step2'))xml_extra_video_step2($mv3YztXmDFiT, $this->iXkV1DXrsnU); if($this->iXkV1DXrsnU['xs_video_extract']||!isset($this->iXkV1DXrsnU['xs_video_extract'])) { if(strstr($mv3YztXmDFiT['playerloc'],'mtv.com')) { $qFRPmUDRi = $Nt_1IROZP14owm4DAeH->fetch('http://www.mtv.com/player/embed/AS3/configuration.jhtml?vid='.$mv3YztXmDFiT['vid'],0,true, false, '', array('skipip' => true));
																													 if(preg_match('#(<feed>.*?</feed>)#is', $qFRPmUDRi['content'], $fm)) $qFRPmUDRi['content'] = $fm[1]; if(preg_match('#<media\:thumbnail url="(.*?)"#', $qFRPmUDRi['content'], $fm)) $mv3YztXmDFiT['thumb'] = $fm[1]; if(preg_match('#duration="(\d+?)"#', $qFRPmUDRi['content'], $fm)) $mv3YztXmDFiT['dur'] = $fm[1]; if(preg_match('#<pubDate>(.+?)<#', $qFRPmUDRi['content'], $fm)) $mv3YztXmDFiT['pubdate'] = date('Y-m-d\TH:i:s+00:00',strtotime($fm[1])); if(preg_match('#<title>(.+?)<#', $qFRPmUDRi['content'], $fm)) $mv3YztXmDFiT['title'] = $fm[1]; if(preg_match('#<description>(.+?)<#', $qFRPmUDRi['content'], $fm)) $mv3YztXmDFiT['desc'] = $fm[1]; if(preg_match('#<media:player url="(.+?)"#', $qFRPmUDRi['content'], $fm)) $mv3YztXmDFiT['playerloc'] = $fm[1]; } if(preg_match('#youtube(-nocookie)?\.com#', $mv3YztXmDFiT['playerloc'])) { $qFRPmUDRi = $Nt_1IROZP14owm4DAeH->fetch('http://gdata.youtube.com/feeds/api/videos/'.$mv3YztXmDFiT['vid'],0,true, false, '', array('skipip' => true));
																													 if(preg_match('#<media\:thumbnail url="(.*?)"#', $qFRPmUDRi['content'], $fm)) $mv3YztXmDFiT['thumb'] = $fm[1]; if(preg_match('#yt:duration seconds=[\'"](\d+)#', $qFRPmUDRi['content'], $fm)) $mv3YztXmDFiT['dur'] = $fm[1]; if(preg_match('#<published>(.+?)<#', $qFRPmUDRi['content'], $fm)) $mv3YztXmDFiT['pubdate'] = $fm[1]; if(preg_match('#<title[^>]*?>([^<]+?)<#', $qFRPmUDRi['content'], $fm))
																													$mv3YztXmDFiT['title'] = $fm[1];
																													if(preg_match('#<media\:description[^>]*?>([^<]+?)<#', $qFRPmUDRi['content'], $fm))
																													$mv3YztXmDFiT['desc'] = $fm[1];
																													}
																													if(strstr($mv3YztXmDFiT['playerloc'],'video.google.com'))
																													{
																													$qFRPmUDRi = $Nt_1IROZP14owm4DAeH->fetch('http://video.google.com/videofeed?docid='.$mv3YztXmDFiT['vid'],0,true, false, '', array('skipip' => true));
																													if(preg_match('#<media\:thumbnail url="(.*?)"#', $qFRPmUDRi['content'], $fm))
																													$mv3YztXmDFiT['thumb'] = $fm[1];
																													if(preg_match('#duration="(\d+?)"#', $qFRPmUDRi['content'], $fm))
																													$mv3YztXmDFiT['dur'] = $fm[1];
																													if(preg_match('#<pubDate>(.+?)<#', $qFRPmUDRi['content'], $fm))
																													$mv3YztXmDFiT['pubdate'] = date('Y-m-d\TH:i:s+00:00',strtotime($fm[1]));
																													if(preg_match('#<title>(.+?)<#', $qFRPmUDRi['content'], $fm))
																													$mv3YztXmDFiT['title'] = $fm[1];
																													if(preg_match('#<description>(.+?)<#', $qFRPmUDRi['content'], $fm))
																													$mv3YztXmDFiT['desc'] = $fm[1];
																													}
																													if(strstr($mv3YztXmDFiT['playerloc'],'vimeo.com'))
																													{
																													$qFRPmUDRi = $Nt_1IROZP14owm4DAeH->fetch($q='http://vimeo.com/api/v2/video/'.$mv3YztXmDFiT['vid'].'.xml',0,true, false, '', array('skipip' => true));
																													if(preg_match('#<thumbnail_medium>(.*?)<#', $qFRPmUDRi['content'], $fm))
																													$mv3YztXmDFiT['thumb'] = $fm[1];
																													if(preg_match('#<duration>(\d+)#', $qFRPmUDRi['content'], $fm))
																													$mv3YztXmDFiT['dur'] = $fm[1];
																													if(preg_match('#<upload_date>(.+?)<#', $qFRPmUDRi['content'], $fm))
																													$mv3YztXmDFiT['pubdate'] = date('Y-m-d\TH:i:s+00:00',strtotime($fm[1]));
																													if(preg_match('#<title>(.+?)<#', $qFRPmUDRi['content'], $fm))
																													$mv3YztXmDFiT['title'] = $fm[1];
																													if(preg_match('#<description>(.+?)<#', $qFRPmUDRi['content'], $fm))
																													$mv3YztXmDFiT['desc'] = $fm[1];
																													}
																													if(strstr($mv3YztXmDFiT['playerloc'],'blip.tv'))
																													{
																													$qFRPmUDRi = $Nt_1IROZP14owm4DAeH->fetch($q='http://blip.tv/players/episode/'.$mv3YztXmDFiT['vid'].'?skin=rss',0,true, false, '', array('skipip' => true));
																													if(
																													preg_match('#<blip:smallThumbnail>(.*?)<#', $qFRPmUDRi['content'], $fm)||
																													preg_match('#<media\:thumbnail url="(.*?)"#', $qFRPmUDRi['content'], $fm)||
																													preg_match('#<blip:picture>(.*?)<#', $qFRPmUDRi['content'], $fm)
																													)
																													$mv3YztXmDFiT['thumb'] = $fm[1];
																													if(preg_match('#<blip:runtime>(\d+)#', $qFRPmUDRi['content'], $fm))
																													$mv3YztXmDFiT['dur'] = $fm[1];
																													if(preg_match('#<blip:datestamp>(.+?)<#', $qFRPmUDRi['content'], $fm))
																													$mv3YztXmDFiT['pubdate'] = date('Y-m-d\TH:i:s+00:00',strtotime($fm[1]));
																													if(preg_match('#<item>.*?<title>(.+?)<#is', $qFRPmUDRi['content'], $fm))
																													$mv3YztXmDFiT['title'] = $fm[1];
																													if(preg_match('#<item>.*?<description>(?:<!\[CDATA\[)?(.+?)(?:\]\]>)?</description>#is', $qFRPmUDRi['content'], $fm)){
																													$mv3YztXmDFiT['desc'] = trim(strip_tags($fm[1]));
																													}
																													}
																													if(strstr($mv3YztXmDFiT['playerloc'],'dailymotion.com'))
																													{
																													$qFRPmUDRi = $Nt_1IROZP14owm4DAeH->fetch($q='https://api.dailymotion.com/video/'.$mv3YztXmDFiT['vid'].'?fields=title,url,thumbnail_medium_url,tags,published,created_time,description,duration',0,true,
																													false, '', array('skipip' => true));
																													$qFRPmUDRi['content'] = stripslashes($qFRPmUDRi['content']);
																													if(preg_match('#"thumbnail_medium_url":"(.*?)"#', $qFRPmUDRi['content'], $fm))
																													$mv3YztXmDFiT['thumb'] = $fm[1];
																													if(preg_match('#"duration":"(\d+?)"#', $qFRPmUDRi['content'], $fm))
																													$mv3YztXmDFiT['dur'] = $fm[1];
																													if(preg_match('#"created_time":"(.+?)"#', $qFRPmUDRi['content'], $fm))
																													$mv3YztXmDFiT['pubdate'] = date('Y-m-d\TH:i:s+00:00',$fm[1]);
																													if(preg_match('#"title":"(.+?)"#', $qFRPmUDRi['content'], $fm))
																													$mv3YztXmDFiT['title'] = $fm[1];
																													if(preg_match('#"description":"(.+?)"#', $qFRPmUDRi['content'], $fm))
																													$mv3YztXmDFiT['desc'] = $fm[1];
																													}
																													}
																													$xz = '/video';
																													return $mv3YztXmDFiT;
																													}
																													function MddRgpIor($urls_completed, &$WH3SIotgdvUyfre)
																													{
																													global $fWF3L71eqllSq, $FTZnv5MP3HN, $bJhviH6UA, $sm_proc_list, $G2zCcihGLQl, $J0guAv8GXYn6AN38fxM, $qcjrymCYbzs62p2m;
																													$SgSv9EHvXQ8D = $this->iXkV1DXrsnU['xs_chlog'];
																													$p3RMgGPJdKj = implode('', file(Jdp4o0I89UFO.'sitemap_xml_tpl.xml'));
																													preg_match('#^(.*)%URLS_LIST_FROM%(.*)%URLS_LIST_TO%(.*)$#is', $p3RMgGPJdKj, $fWF3L71eqllSq);
																													$fWF3L71eqllSq[1] = str_replace('www.xml-sitemaps.com', 'www.xml-sitemaps.com ('. A4sNJQoe6O47I_YC4.')', $fWF3L71eqllSq[1]);
																													$fWF3L71eqllSq[1] = str_replace('%GEN_URL%', $this->iXkV1DXrsnU['gendom'], $fWF3L71eqllSq[1]);
																													if($this->iXkV1DXrsnU['xs_disable_xsl'])
																													$fWF3L71eqllSq[1] = preg_replace('#<\?xml-stylesheet.*\?>#', '', $fWF3L71eqllSq[1]);
																													$tHSKS4COUobk6O = implode('', file(Jdp4o0I89UFO.'sitemap_ror_tpl.xml'));
																													preg_match('#^(.*)%URLS_LIST_FROM%(.*)%URLS_LIST_TO%(.*)$#is', $tHSKS4COUobk6O, $FTZnv5MP3HN);
																													$RKwdWhsAFuDrxw3i6 = implode('', file(Jdp4o0I89UFO.'sitemap_base_tpl.xml'));
																													preg_match('#^(.*)%URLS_LIST_FROM%(.*)%URLS_LIST_TO%(.*)$#is', $RKwdWhsAFuDrxw3i6, $bJhviH6UA);
																													$this->Xfcs5RdKZjSaEqvTYT = $this->iXkV1DXrsnU['xs_sm_size']?$this->iXkV1DXrsnU['xs_sm_size']:50000;
																													$this->sm_filesplit = $this->iXkV1DXrsnU['xs_sm_filesize']?$this->iXkV1DXrsnU['xs_sm_filesize']:10;
																													$this->sm_filesplit = max(intval($this->sm_filesplit*1024*1024),2000)-1000;
																													if(!$this->iXkV1DXrsnU['xs_imginfo'])
																													unset($this->fjOiR1rimG[1]);
																													if(!$this->iXkV1DXrsnU['xs_videoinfo'])
																													unset($this->fjOiR1rimG[2]);
																													if(!$this->iXkV1DXrsnU['xs_newsinfo'])
																													unset($this->fjOiR1rimG[3]);
																													if(!$this->iXkV1DXrsnU['xs_makemob'])
																													unset($this->fjOiR1rimG[4]);
																													$ctime = date('Y-m-d H:i:s');
																													$Yqz1QyXnf8Zlfu9jU = 0;
																													global $g9mWWYIteSa7dD7;
																													$tt = array('<','>');
																													foreach ($tt as $ulCVuyvzZwsip )
																													$g9mWWYIteSa7dD7[$ulCVuyvzZwsip] = '&#'.ord($ulCVuyvzZwsip).';';
																													for($i=0;$i<31;$i++)
																													$g9mWWYIteSa7dD7[chr($i)] = '&#'.$i.';';
																													$g9mWWYIteSa7dD7[chr(0)] = $g9mWWYIteSa7dD7[chr(10)] = $g9mWWYIteSa7dD7[chr(13)] = '';
																													$g9mWWYIteSa7dD7[' '] = '%20';
																													$pf = 0;
																													$XvU49oK_Vd = intval($G2zCcihGLQl['istart']);
																													$this->e5VXUaptWL7P($G2zCcihGLQl);
																													if($this->iXkV1DXrsnU['xs_maketxt'])
																													{
																													$ifLJ96S2XFSDmmWXE = $this->JRevVhPXx6ik['fopen'](bjmS1HQhkPEjp1QMl.$this->blUx9Th8GWx0bsSC, $XvU49oK_Vd?'a':'w');
																													if(!$ifLJ96S2XFSDmmWXE)$qcjrymCYbzs62p2m[] = bjmS1HQhkPEjp1QMl.$this->blUx9Th8GWx0bsSC;
																													}
																													if($this->iXkV1DXrsnU['xs_makeror'])
																													{
																													$DViaBKXmteSZF4cgvzj = fopen(z_fhGrViQaOeql9, $XvU49oK_Vd?'a':'w');
																													$rc = str_replace('%INIT_URL%', $this->iXkV1DXrsnU['xs_initurl'], $FTZnv5MP3HN[1]);
																													if($DViaBKXmteSZF4cgvzj)
																													fwrite($DViaBKXmteSZF4cgvzj, $rc);
																													else
																													$qcjrymCYbzs62p2m[] = z_fhGrViQaOeql9;
																													}
																													foreach($sm_proc_list as $k=>$G3iGwEa5RT3)
																													$sm_proc_list[$k]->IkN8UDC3Sq4($this->iXkV1DXrsnU, $this->JRevVhPXx6ik, $this->xZqlshGDcY);
																													for($i=$xn=$XvU49oK_Vd;$i<count($urls_completed);$i++,$xn++)
																													{   
																													BDURPicA56HxjrUUp(array(
																													'cmd'=> 'info',
																													'id' => 'percprog',
																													'text'=> number_format($i*100/count($urls_completed),0).'%'
																													));
																													$RvGpMMUREL77 = $this->ZzKB7k6G8nHCQRqPK();
																													if($RvGpMMUREL77 && ($i != $XvU49oK_Vd))
																													{
																													dxY5KOhQceAuFRoi($J0guAv8GXYn6AN38fxM,hVgV5J75NEESyCQgUY(array('istart'=>$i,'rinfo'=>$this->cELF4rAmlQsI9AR)));
																													}
																													if($this->iXkV1DXrsnU['xs_memsave'])
																													{
																													$cu = dYfVkEYUS1map3XFd8($urls_completed[$i]);
																													}else
																													$cu = &$urls_completed[$i];
																													$l = $this->JiNZdZTQFJ($cu['link']);
																													$cu['link'] = $l;
																													if($SgSv9EHvXQ8D) $WH3SIotgdvUyfre[]=$l;
																													$t = $this->nGj0r0BbusL($cu['t']);
																													$d = $this->nGj0r0BbusL($cu['d'] ? $cu['d'] : $cu['t'], true);
																													$spSCVOMAe = '';
																													if($cu['clm'])
																													$spSCVOMAe = $cu['clm'];
																													else
																													switch($this->iXkV1DXrsnU['xs_lastmod']){
																													case 1:$spSCVOMAe = $cu['lm']?$cu['lm']:$ctime;break;
																													case 2:$spSCVOMAe = $ctime;break;
																													case 3:$spSCVOMAe = $this->iXkV1DXrsnU['xs_lastmodtime'];break;
																													}
																													$jLo1X8O3OGZlDH54AjS = $q9XceTZtmgERYb = false;
																													if($cu['p'])
																													$p = $cu['p'];
																													else
																													{
																													$p = $this->iXkV1DXrsnU['xs_priority'];
																													if($this->iXkV1DXrsnU['xs_autopriority'])
																													{
																													$p = $p*pow($this->iXkV1DXrsnU['xs_descpriority']?$this->iXkV1DXrsnU['xs_descpriority']:0.8,$cu['o']);
																													if($this->IIcbczWAX09NsrG)
																													{
																													$jLo1X8O3OGZlDH54AjS = true;
																													$q9XceTZtmgERYb = !in_array($cu['link'], $this->IIcbczWAX09NsrG)||$this->urls_prevnews[$cu['link']];
																													if($q9XceTZtmgERYb)
																													$p=0.95;
																													}
																													$p = max(0.0001,min($p,1.0));
																													$p = @number_format($p, 4);
																													}
																													}
																													if($spSCVOMAe){
																													$spSCVOMAe = strtotime($spSCVOMAe);
																													$spSCVOMAe = gmdate('Y-m-d\TH:i:s+00:00',$spSCVOMAe);
																													}
																													$f = $cu['f']?$cu['f']:$this->iXkV1DXrsnU['xs_freq'];
																													$cCqeu6KEd4LFk = array(
																													'URL'=>$l,
																													'TITLE'=>$t,
																													'DESC'=>($d),
																													'PERIOD'=>$f,
																													'LASTMOD'=>$spSCVOMAe,
																													'ORDER'=>$cu['o'],
																													'PRIORITY'=>$p
																													);
																													if($this->iXkV1DXrsnU['xs_makemob'])
																													{
																													$this->AfTRVXncZI6Bitp(array_merge($cCqeu6KEd4LFk, array('ismob'=>true)), $fWF3L71eqllSq[2], 4);
																													}
																													
																													$this->AfTRVXncZI6Bitp($cCqeu6KEd4LFk, $fWF3L71eqllSq[2], 0);
																													$xz = 'img';
																													if($cu['i'])
																													{
																													foreach($cu['i'] as $im)
																													$cCqeu6KEd4LFk['imgs'][] = array(
																													'iurl'=>$this->JiNZdZTQFJ($im[0]), 
																													'caption'=>$this->nGj0r0BbusL($im[1], true)
																													);
																													if($cCqeu6KEd4LFk['imgs'])
																													{
																													$this->imgno+=count($cCqeu6KEd4LFk['imgs']);
																													$this->AfTRVXncZI6Bitp($cCqeu6KEd4LFk, $fWF3L71eqllSq[2], 1);
																													}
																													unset($cCqeu6KEd4LFk['imgs']);
																													}
																													$xz = '/img';
																													$xz = 'video';
																													if($cu['v'])
																													{
																													foreach($cu['v'] as $im)
																													{
																													$xz = $this->C5VWcxw36h(array(
																													'vid' => $im[1],
																													'title'=>$t,
																													'desc'=>($d),
																													'playerloc'=>$im[0],
																													));
																													if($xz['thumb'])
																													$cCqeu6KEd4LFk['videos'][] = $xz;
																													}
																													if($cCqeu6KEd4LFk['videos'])
																													{
																													$this->videos_no+=count($cCqeu6KEd4LFk['videos']);
																													$this->AfTRVXncZI6Bitp($cCqeu6KEd4LFk, $fWF3L71eqllSq[2], 2);
																													}
																													}
																													$xz = '/video';
																													if($this->iXkV1DXrsnU['xs_maketxt'] && $ifLJ96S2XFSDmmWXE)
																													$this->JRevVhPXx6ik['fwrite']($ifLJ96S2XFSDmmWXE, $cu['link']."\n");
																													foreach($sm_proc_list as $G3iGwEa5RT3)
																													$G3iGwEa5RT3->B0bZK2_9KnR8WXXzmsf($cCqeu6KEd4LFk);
																													if($this->iXkV1DXrsnU['xs_makeror'] && $DViaBKXmteSZF4cgvzj){
																													if($this->iXkV1DXrsnU['xs_ror_unique']){
																													$t=$cCqeu6KEd4LFk['TITLE'];
																													$d=$cCqeu6KEd4LFk['DESC'];
																													while($ZNulaCcO5edar0rP=$ai[md5('t'.$t)]++){
																													$t=$cCqeu6KEd4LFk['TITLE'].' '.$ZNulaCcO5edar0rP;
																													}
																													while($ZNulaCcO5edar0rP=$ai[md5('d'.$d)]++){
																													$d=$cCqeu6KEd4LFk['DESC'].' '.$ZNulaCcO5edar0rP;
																													}
																													$cCqeu6KEd4LFk['TITLE']=$t;
																													$cCqeu6KEd4LFk['DESC']=$d;
																													}
																													fwrite($DViaBKXmteSZF4cgvzj, $this->xZqlshGDcY->NncQLfQqsOrhLw_lKS($FTZnv5MP3HN[2],$cCqeu6KEd4LFk));
																													}
																													}
																													$this->aqAxgNGqxV();
																													if($this->iXkV1DXrsnU['xs_maketxt'])
																													{
																													$this->JRevVhPXx6ik['fclose']($ifLJ96S2XFSDmmWXE);
																													@chmod(bjmS1HQhkPEjp1QMl.$this->blUx9Th8GWx0bsSC, 0666);
																													}
																													if($this->iXkV1DXrsnU['xs_makeror'])
																													{
																													if($DViaBKXmteSZF4cgvzj)
																													fwrite($DViaBKXmteSZF4cgvzj, $FTZnv5MP3HN[3]);
																													fclose($DViaBKXmteSZF4cgvzj);
																													}
																													foreach($sm_proc_list as $G3iGwEa5RT3)
																													$G3iGwEa5RT3->jKfsD0XVw81EIu2rj();
																													dxY5KOhQceAuFRoi($J0guAv8GXYn6AN38fxM,hVgV5J75NEESyCQgUY(array('done'=>true)));
																													BDURPicA56HxjrUUp(array('cmd'=> 'info','id' => 'percprog',''));
																													}
																													function J288sfitpupJnEcw3($ygddcsZcedjzZC)
																													{
																													for($i=0;file_exists($sf=sMuf2pf0iKaQ.fbWEyZNrRSnYdpJt($i,$ygddcsZcedjzZC).$this->blUx9Th8GWx0bsSC);$i++){
																													unlink($sf);
																													}
																													}
																													function SWv7WC7WEJVO($ygddcsZcedjzZC)
																													{
																													global $qcjrymCYbzs62p2m;
																													for($i=0;file_exists(sMuf2pf0iKaQ.($sf=fbWEyZNrRSnYdpJt($i,$ygddcsZcedjzZC).$this->blUx9Th8GWx0bsSC));$i++){
																													if(!copy(sMuf2pf0iKaQ.$sf,$this->furl_p.$sf))
																													{
																													if($cn = @fopen($this->furl_p.$sf, 'w')){
																													@fwrite($cn, file_get_contents(sMuf2pf0iKaQ.$sf));
																													@fclose($cn);
																													}else
																													if(file_exists(sMuf2pf0iKaQ.$sf))
																													{
																													$qcjrymCYbzs62p2m[]=$this->furl_p.$sf;
																													}
																													}
																													
																													@chmod(sMuf2pf0iKaQ.$sf, 0666);
																													}
																													}
																													function btBwwZXxWS($ygddcsZcedjzZC, $YHHPuGcJpxLDUfERty = 0)
																													{
																													$cn = '';
																													for($i=0;file_exists($sf=sMuf2pf0iKaQ.fbWEyZNrRSnYdpJt($i,$ygddcsZcedjzZC).$this->blUx9Th8GWx0bsSC);$i++)
																													{
																													
																													$cn .= $this->blUx9Th8GWx0bsSC?implode('',gzfile($sf)):GHJEfA2QYqwa($sf);
																													if($i>200)break;
																													}
																													preg_match_all('#<loc>(.*?)</loc>'.($YHHPuGcJpxLDUfERty ? '.*?<news:publication_date>(.*?)</news:publication_date>' : '').'#is',$cn,$um);
																													if($YHHPuGcJpxLDUfERty)
																													{
																													$al = array();
																													foreach($um[1] as $i=>$l)
																													{
																													if(time()-strtotime($um[2][$i])<=$YHHPuGcJpxLDUfERty*24*3600)
																													$al[$l] = $um[2][$i];
																													}
																													return $al;
																													}
																													return $um[1];
																													}
																													}
																													$EYyBXYy9WWbLGYL5iQ = new XMLCreator();
																													



































































































